#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */

    /* DDR Regions */
    {"Hypervisor",      0x80000000, 0x00600000,   AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
    {"IPC SHM",         0x805D0000, 0x00020000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"BOOT INFO",       0x805F0000, 0x00010000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"MPSS EFS",        0x80600000, 0x00100000,   AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
    {"AOP CMD DB",      0x80860000, 0x00020000,   AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"SMEM",            0x80900000, 0x00200000,   AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"TZApps Reserved", 0x82400000, 0x09600000,   HobOnlyNoCacheSetting, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"PIL Reserved",    0x8BF00000, 0x06500000,   AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"Sched Heap",      0x9BC00000, 0x00400000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"Display Reserved",0x9C000000, 0x02400000,   AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},
    {"DBI Dump",        0x9E400000, 0x00F00000,   NoHob,  MMAP_IO, INITIALIZED, Conv,   UNCACHED_UNBUFFERED_XN},
    {"FV Region",       0x9F800000, 0x00200000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"ABOOT FV",        0x9FA00000, 0x00200000,   AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
    {"UEFI FD",         0x9FC00000, 0x00300000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"SEC Heap",        0x9FF00000, 0x0008C000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"CPU Vectors",     0x9FF8C000, 0x00001000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"MMU PageTables",  0x9FF8D000, 0x00003000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"UEFI Stack",      0x9FF90000, 0x00040000,   AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"Log Buffer",      0x9FFF7000, 0x00008000,   AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
    {"Info Blk",        0x9FFFF000, 0x00001000,   AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
    {"Kernel",          0xA0000000, 0x10000000,   AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
    {"DXE Heap",        0xB0000000, 0x04500000,   AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

    /* RAM partition regions */
    {"RAM Partition",   0xFFC20000,0x1803E0000,   AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

    /* Other memory regions */
    {"IMEM Base",       0x14680000, 0x00040000,   NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {"IMEM Cookie Base",0x146BF000, 0x00001000,   AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},

    /* Register regions */
    {"IPC_ROUTER_TOP",  0x00400000, 0x00100000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"SECURITY CONTROL",0x00780000, 0x00007000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"QUPV3_2_GSI",     0x00800000, 0x000D0000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"QUPV3_0_GSI",     0x00900000, 0x000D0000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"QUPV3_1_GSI",     0x00A00000, 0x000D0000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PRNG_CFG_PRNG",   0x00790000, 0x00010000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"CRYPTO0 CRYPTO",  0x01DC0000, 0x00040000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TCSR_TCSR_REGS",  0x01FC0000, 0x00030000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"GPU_GMU_CX_BLK",  0x02C7D000, 0x00002000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"GPU_CC",          0x02C90000, 0x0000A000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"QUPV3_SSC_GSI",   0x05A00000, 0x000D0000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PERIPH_SS",       0x08800000, 0x00200000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"USB30_PRIM",      0x0A600000, 0x0011B000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"USB_RUMI",        0x0A720000, 0x00010000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"USB30_SEC",       0x0A800000, 0x0011B000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"AOSS",            0x0B000000, 0x04000000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TLMM_WEST",       0x0F100000, 0x00300000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TLMM_SOUTH",      0x0F500000, 0x00300000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TLMM_NORTH",      0x0F900000, 0x00300000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"SMMU",            0x15000000, 0x000D0000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"APSS_HM",         0x17800000, 0x0d981000,   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
    return gDeviceMemoryDescriptorEx;
}
