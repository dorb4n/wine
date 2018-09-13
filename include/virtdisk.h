/*
 * Copyright 2017 Louis Lenders
 * Copyright 2018 Gijs Vermeulen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_VIRTDISK_DLL_H
#define __WINE_VIRTDISK_DLL_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN     0
#define VIRTUAL_STORAGE_TYPE_DEVICE_ISO         1
#define VIRTUAL_STORAGE_TYPE_DEVICE_VHD         2

typedef enum _ATTACH_VIRTUAL_DISK_FLAG {
    ATTACH_VIRTUAL_DISK_FLAG_NONE                   = 0x00,
    ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY              = 0x01,
    ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER        = 0x02,
    ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME     = 0x04,
    ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST          = 0x08,
    ATTACH_VIRTUAL_DISK_FLAG_NO_SECURITY_DESCRIPTOR = 0x10
} ATTACH_VIRTUAL_DISK_FLAG;

typedef enum _ATTACH_VIRTUAL_DISK_VERSION {
    ATTACH_VIRTUAL_DISK_VERSION_UNSPECIFIED,
    ATTACH_VIRTUAL_DISK_VERSION_1
} ATTACH_VIRTUAL_DISK_VERSION;

typedef enum _COMPACT_VIRTUAL_DISK_FLAG {
    COMPACT_VIRTUAL_DISK_FLAG_NONE           = 0x00,
    COMPACT_VIRTUAL_DISK_FLAG_NO_ZERO_SCAN   = 0x01,
    COMPACT_VIRTUAL_DISK_FLAG_NO_BLOCK_MOVES = 0x02
} COMPACT_VIRTUAL_DISK_FLAG;

typedef enum _COMPACT_VIRTUAL_DISK_VERSION {
    COMPACT_VIRTUAL_DISK_VERSION_UNSPECIFIED,
    COMPACT_VIRTUAL_DISK_VERSION_1
} COMPACT_VIRTUAL_DISK_VERSION;

typedef enum _DEPENDENT_DISK_FLAG
{
    DEPENDENT_DISK_FLAG_NONE                 = 0x00000000,
    DEPENDENT_DISK_FLAG_MULT_BACKING_FILES   = 0x00000001,
    DEPENDENT_DISK_FLAG_FULLY_ALLOCATED      = 0x00000002,
    DEPENDENT_DISK_FLAG_READ_ONLY            = 0x00000004,
    DEPENDENT_DISK_FLAG_REMOTE               = 0x00000008,
    DEPENDENT_DISK_FLAG_SYSTEM_VOLUME        = 0x00000010,
    DEPENDENT_DISK_FLAG_SYSTEM_VOLUME_PARENT = 0x00000020,
    DEPENDENT_DISK_FLAG_REMOVABLE            = 0x00000040,
    DEPENDENT_DISK_FLAG_NO_DRIVE_LETTER      = 0x00000080,
    DEPENDENT_DISK_FLAG_PARENT               = 0x00000100,
    DEPENDENT_DISK_FLAG_NO_HOST_DISK         = 0x00000200,
    DEPENDENT_DISK_FLAG_PERMANENT_LIFETIME   = 0x00000400
} DEPENDENT_DISK_FLAG;

typedef enum _EXPAND_VIRTUAL_DISK_VERSION {
    EXPAND_VIRTUAL_DISK_VERSION_UNSPECIFIED,
    EXPAND_VIRTUAL_DISK_VERSION_1
} EXPAND_VIRTUAL_DISK_VERSION;

typedef enum _DETACH_VIRTUAL_DISK_FLAG {
    DETACH_VIRTUAL_DISK_FLAG_NONE = 0x00000000
} DETACH_VIRTUAL_DISK_FLAG;

typedef enum _EXPAND_VIRTUAL_DISK_FLAG {
    EXPAND_VIRTUAL_DISK_FLAG_NONE = 0x00000000
} EXPAND_VIRTUAL_DISK_FLAG;

typedef enum _GET_STORAGE_DEPENDENCY_FLAG
{
    GET_STORAGE_DEPENDENCY_FLAG_NONE         = 0x00,
    GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES = 0x01,
    GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE  = 0x02
} GET_STORAGE_DEPENDENCY_FLAG;

typedef enum _MIRROR_VIRTUAL_DISK_FLAG {
    MIRROR_VIRTUAL_DISK_FLAG_NONE           = 0x00,
    MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE  = 0x01
} MIRROR_VIRTUAL_DISK_FLAG;

typedef enum _MIRROR_VIRTUAL_DISK_VERSION {
    MIRROR_VIRTUAL_DISK_VERSION_UNSPECIFIED,
    MIRROR_VIRTUAL_DISK_VERSION_1
} MIRROR_VIRTUAL_DISK_VERSION;

typedef enum _MERGE_VIRTUAL_DISK_FLAG {
    MERGE_VIRTUAL_DISK_FLAG_NONE = 0x00000000
} MERGE_VIRTUAL_DISK_FLAG;

typedef enum _STORAGE_DEPENDENCY_INFO_VERSION
{
    STORAGE_DEPENDENCY_INFO_VERSION_UNSPECIFIED = 0x0,
    STORAGE_DEPENDENCY_INFO_VERSION_1           = 0x1,
    STORAGE_DEPENDENCY_INFO_VERSION_2           = 0x2
} STORAGE_DEPENDENCY_INFO_VERSION;

typedef enum _VIRTUAL_DISK_ACCESS_MASK {
    VIRTUAL_DISK_ACCESS_NONE        = 0x00000000,
    VIRTUAL_DISK_ACCESS_ATTACH_RO   = 0x00010000,
    VIRTUAL_DISK_ACCESS_ATTACH_RW   = 0x00020000,
    VIRTUAL_DISK_ACCESS_DETACH      = 0x00040000,
    VIRTUAL_DISK_ACCESS_GET_INFO    = 0x00080000,
    VIRTUAL_DISK_ACCESS_CREATE      = 0x00100000,
    VIRTUAL_DISK_ACCESS_METAOPS     = 0x00200000,
    VIRTUAL_DISK_ACCESS_READ        = 0x000d0000,
    VIRTUAL_DISK_ACCESS_ALL         = 0x003f0000,
    VIRTUAL_DISK_ACCESS_WRITABLE    = 0x00320000
} VIRTUAL_DISK_ACCESS_MASK;

typedef struct _VIRTUAL_STORAGE_TYPE
{
    ULONG DeviceId;
    GUID  VendorId;
} VIRTUAL_STORAGE_TYPE, *PVIRTUAL_STORAGE_TYPE;

typedef struct _ATTACH_VIRTUAL_DISK_PARAMETERS {
    ATTACH_VIRTUAL_DISK_VERSION Version;
    __C89_NAMELESS union {
        struct {
            ULONG Reserved;
        } Version1;
    } DUMMYUNIONNAME;
} ATTACH_VIRTUAL_DISK_PARAMETERS, *PATTACH_VIRTUAL_DISK_PARAMETERS;

typedef struct _COMPACT_VIRTUAL_DISK_PARAMETERS {
    COMPACT_VIRTUAL_DISK_VERSION Version;
    __C89_NAMELESS union {
        struct {
            ULONG Reserved;
        } Version1;
    } DUMMYUNIONNAME;
} COMPACT_VIRTUAL_DISK_PARAMETERS, *PCOMPACT_VIRTUAL_DISK_PARAMETERS;

typedef struct _EXPAND_VIRTUAL_DISK_PARAMETERS {
    EXPAND_VIRTUAL_DISK_VERSION Version;
    __C89_NAMELESS union {
        struct {
            ULONGLONG NewSize;
        } Version1;
    } DUMMYUNIONNAME;
} EXPAND_VIRTUAL_DISK_PARAMETERS, *PEXPAND_VIRTUAL_DISK_PARAMETERS;

typedef struct _STORAGE_DEPENDENCY_INFO_TYPE_1
{
    DEPENDENT_DISK_FLAG  DependencyTypeFlags;
    ULONG                ProviderSpecificFlags;
    VIRTUAL_STORAGE_TYPE VirtualStorageType;
} STORAGE_DEPENDENCY_INFO_TYPE_1, *PSTORAGE_DEPENDENCY_INFO_TYPE_1;

typedef struct _STORAGE_DEPENDENCY_INFO_TYPE_2
{
    DEPENDENT_DISK_FLAG  DependencyTypeFlags;
    ULONG                ProviderSpecificFlags;
    VIRTUAL_STORAGE_TYPE VirtualStorageType;
    ULONG                AncestorLevel;
    PWSTR                DependencyDeviceName;
    PWSTR                HostVolumeName;
    PWSTR                DependentVolumeName;
    PWSTR                DependentVolumeRelativePath;
} STORAGE_DEPENDENCY_INFO_TYPE_2, *PSTORAGE_DEPENDENCY_INFO_TYPE_2;

typedef struct _STORAGE_DEPENDENCY_INFO
{
    STORAGE_DEPENDENCY_INFO_VERSION Version;
    ULONG                           NumberEntries;
#if !defined(__WINESRC__) && (defined(_MSC_EXTENSIONS) || ((defined(__GNUC__) && __GNUC__ >= 3)))
    __C89_NAMELESS union
    {
        STORAGE_DEPENDENCY_INFO_TYPE_1 Version1Entries[];
        STORAGE_DEPENDENCY_INFO_TYPE_2 Version2Entries[];
    } __C89_NAMELESSUNIONNAME;
#endif
} STORAGE_DEPENDENCY_INFO, *PSTORAGE_DEPENDENCY_INFO;

typedef struct _VIRTUAL_DISK_PROGRESS {
    DWORD     OperationStatus;
    ULONGLONG CurrentValue;
    ULONGLONG CompletionValue;
} VIRTUAL_DISK_PROGRESS, *PVIRTUAL_DISK_PROGRESS;

DWORD WINAPI GetStorageDependencyInformation(HANDLE obj, GET_STORAGE_DEPENDENCY_FLAG flags, ULONG size, STORAGE_DEPENDENCY_INFO *info, ULONG *used);

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_VIRTDISK_DLL_H */
