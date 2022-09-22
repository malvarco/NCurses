
# NCurses listings tested on FreeBSD 13

### Original sources from:
* Casual Coder's NCurses Youtube Video Tutorial ( https://www.youtube.com/playlist?list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v )

## FreeBSD 13 compiling

For compiling, Ncurses package must be installed.

Using the Terminal:  
`gcc source.c -o binaryfile -lncurses`

### In Codeblocks, go to Menu > Project > Build Options...  
    * In Linker settings > Link libraries:  
         + /usr/lib/libncurses.so

### Run using terminal:  
`./code5`
