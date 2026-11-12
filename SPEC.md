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
The header contains the basic information about the module needed by the manager.

![pkeX header map](res/pkex.header.png)
