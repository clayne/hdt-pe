# HDT Physics Extension for Original Skyrim

HDT Physics Extension for original Skyrim (32bit Skyrim), with some small update to the source code for easier to compile.

This repo is in maintenance mode, so don't expect new commit now and then, and there will be no feature added, but pull request are welcome. :)

Based on the original HDT Physics Extension version 14.28 source code from [https://code.google.com/archive/p/hdt-pe/](https://code.google.com/archive/p/hdt-pe/).

The source code of HDT Physics Extension is in GNU LGPL license from information in the above link.

## Credits:

	HydrogensaysHDT, original author:
	All credit for development of the base plugin goes to HydrogensaysHDT,
	the original author and developer of the source code.

	Thanks for your work!

---

# Build instruction

## Depencies

- Microsoft Visual Studio 2012
- Havok Physics & Animation SDK 2013.1
Hint hint: "Havok_2013-1-0_PC_XS_win32" or "Havok Engine SDKs"
- [SKSE 1.7.3](http://skse.silverlock.org)
- [Microsoft Detours](https://github.com/Microsoft/Detours)

## Installing depencies

TODO

Directory setup

	C:\DEV\SDK\Havok\hk2013_1_0_r1  Havok Physics
	C:\DEV\Skyrim\Detours           Microsoft Detours
	C:\DEV\Skyrim\hdt-pe            This repository

Put all files from `skse_1_07_03\src\common` in `hdt-pe\common` if duplicate file, don't replace it.

Put all files from `skse_1_07_03\src\skse\skse` in `hdt-pe\skse` if duplicate file, don't replace it.

...

## Building required library

TODO

Detours is compile using `VS2012 x86 Native Tools Command Prompt`

# Building the source code

Open `hdtPhysicsExtensions.sln` using Visual Studio 2012 and build it.
