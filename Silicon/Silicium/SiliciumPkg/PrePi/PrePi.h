/**
  Copyright (c) 2011 - 2020, Arm Limited. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _PREPI_H_
#define _PREPI_H_

#include <PiPei.h>

#include <Library/PcdLib.h>
#include <Library/ArmLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/HobLib.h>
#include <Library/SerialPortLib.h>
#include <Library/ArmPlatformLib.h>

extern UINT64 mSystemMemoryEnd;

RETURN_STATUS
EFIAPI
TimerConstructor ();

VOID
PrePiMain (IN UINT64 StartTimeStamp);

EFI_STATUS
EFIAPI
MemoryPeim (
  IN EFI_PHYSICAL_ADDRESS UefiMemoryBase,
  IN UINT64               UefiMemorySize
  );

EFI_STATUS
EFIAPI
PlatformPeim ();

VOID
BuildMemoryTypeInformationHob ();

EFI_STATUS
GetPlatformPpi (
  IN  EFI_GUID  *PpiGuid,
  OUT VOID     **Ppi
  );

VOID
ArchInitialize ();

VOID
EFIAPI
ProcessLibraryConstructorList ();

#endif /* _PREPI_H_ */
