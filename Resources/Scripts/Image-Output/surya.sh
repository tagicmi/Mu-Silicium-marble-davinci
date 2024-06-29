#!/bin/bash

# Build an Android kernel that is actually UEFI disguised as the Kernel
cat ./BootShim/AARCH64/BootShim.bin "./Build/suryaPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/SURYA_UEFI.fd" > "./Build/suryaPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/SURYA_UEFI.fd-bootshim"||exit 1
gzip -c < "./Build/suryaPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/SURYA_UEFI.fd-bootshim" > "./Build/suryaPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/SURYA_UEFI.fd-bootshim.gz"||exit 1
cat "./Build/suryaPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/SURYA_UEFI.fd-bootshim.gz" ./Resources/DTBs/surya.dtb > ./Resources/bootpayload.bin||exit 1

# Create bootable Android boot.img
python3 ./Resources/Scripts/Image-Output/mkbootimg.py \
  --kernel ./Resources/bootpayload.bin \
  --ramdisk ./Resources/ramdisk \
  --kernel_offset 0x00000000 \
  --ramdisk_offset 0x00000000 \
  --tags_offset 0x00000000 \
  --os_version 13.0.0 \
  --os_patch_level "$(date '+%Y-%m')" \
  --header_version 1 \
  -o Mu-surya.img \
  ||_error "\nFailed to create Android Boot Image!\n"