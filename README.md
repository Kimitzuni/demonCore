<h1 align=center> <img src="docs/demonCoreLogo.png" width=150px>
</br>demonCore</h1>

demonCore aims to be replacements for the GNU Core Utilities, and potentially
other programs.

## Building
To build demonCore, you can either use the Master Makefile, or each programs
individual makefile. For both, you will require 'Make' and GCC to be installed
on your system.

To change options, such as the CFLAGS, you can simply append them to the make
command, like so

```
   make CFLAGS="-O2 -pipe" BUILD="build_directory/"
```

## Current Replacements
> [demonCore Userview](core/userview) \
> A Replacement for GNU's *whoami*

> [Fileout](core/fileout) \
> A Replacement for 'cat'

> [bsh](core/bsh) \
> A Replacement for BASH, and a painfully POSIX Compliant shell written in C

> [no](core/no) \
> A Replacement for 'yes' - Print a string indefinitely

> [truefalse](core/truefalse) \
> "Replacements" for 'true' and 'false'

> [cwd](core/cwd) \
> Print Current Working Directory

> [proc](core/proc) \
> List number of processors

## Other Developer Repositories
[InfinityFloof/demonCore](https://github.com/InfinityFloof/demonCore)

## License
demonCore is licensed under the GNU General Public License, version 2.0