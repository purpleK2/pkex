# pkeX specification
The **p**urple**k**2 **eX**tensions (pkeX, *pee-kex*) system is an interface designed to let the purplek2 kernel load modules and manage their relations between them.

# Goal
The main goal of this interface is to give the necessary information to the kernel to load a certain module file code at the kernel-level and to manage eventual dependencies between them.

# Components
The main components for this interface are the pkeX module files (pkeXs, *pee-kexes*) and the module manager.

## pkeX files
pkeX files are the data that contain the code that enables software extensions or device drivers.
They are ELF shared objects (`e_type = DYN`) of which only kernel-code functions should be relocated. The ELF header and file is preceded by pkeX-specific data of variable length.

## Module manager
The module manager is a kernel-level components that is responsible for choosing the source for loading modules, (eg. bootloader parameters, somewhere on the disk through a specific path).

It is also responsible for avoiding modules, on which others are relying on, to be unloaded to avoid issues when calling potentially unavailable code.

Additional module manager behaviour is specified later on.

# pkeX file format
A pkeX file, excluding the ELF data, is composed of a fixed-size header and at least two tables of variable length.

## pkeX header
The header contains the basic information about the module needed by the manager. It is found at the start of the file.

- **Magic**: a signature for the module format. This MUST be equal to the string `PEXT`. If not, this is an invalid file.
- **Version**: Identifies the pkeX specification revision. Higher 8 bits identify the major version, lower 8 for the minor.
- **Type**: Identifies the module type. Currently supported types are: `PKEX_MOD` (0, offers a software extension), `PKEX_DRV` (1, offers a device driver).
- **Name**: This is an offset into the String table (see [String Table](#)) that tells the name of this driver.
- **Module Major & Minor**: Identifies the version of this module, useful for modules that rely on others. Higher 8 bits for major, lower 8 for minor.
- **String Table Offset**: Offset into the file for the String table (see [String Table](#) below). Not to be confused with ELF's string table.
- **Features Table Offset**: Offset into the file for the Features table (see [Features Table](#) below).
- **Dependencies Table Offset**: Offset into the file for the Dependencies table (see [Dependencies Table](#) below).
- **ELF Offset**: Offset into the file for the start of the ELF file to be executed.

![pkeX header fields](res/pkex.header.png)
