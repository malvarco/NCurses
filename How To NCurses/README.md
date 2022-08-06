# NCurses examples tested on FreeBSD 13 and Windows 10

### Original sources from:
   * https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/

## FreeBSD 13 compiling

For compiling, Ncurses package must be installed.

Using the Terminal:  
`gcc source.c -o binaryfile -lncurses`

### In Codeblocks, go to Menu > Project > Build Options...  
    * In Linker settings > Link libraries:  
         + /usr/lib/libncurses.so

### Run using terminal:  
`./code5`

## Windows 10 Visual Studio compiling

+ The easiest way is to install PDCurses using the utility Vcpkg (https://vcpkg.io/en/index.html).  
+ It's installed using Powershell or Command Prompt.  
+ Create a project in Visual Studio and add one source to it. It should compile without problems.  
+ To use the exe file, you will need the PDCurses.DLL file in the same directory.

