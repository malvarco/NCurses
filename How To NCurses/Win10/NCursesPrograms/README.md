# NCurses examples tested on FreeBSD 13

### Original sources from:
   * https://github.com/cpressey/ncurses_programs

## FreeBSD 13 compiling

For compiling, Ncurses package must be installed.

Using the Terminal:  
`gcc source.c -o binaryfile -lncurses`

### In Codeblocks, go to Menu > Project > Build Options...  
    * In Linker settings > Link libraries:  
         + /usr/lib/libncurses.so

### Run using terminal:  
`./code5`
