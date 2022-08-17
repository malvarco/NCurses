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
