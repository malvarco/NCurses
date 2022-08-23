
# NCurses listings tested on FreeBSD 13

## Listings from the book:
+ Dan Gookin's Guide to Ncurses Programming ( https://www.amazon.com/Dan-Gookins-Guide-Ncurses-Programming-ebook/dp/B075FGJJCS )

## FreeBSD 13 compiling

For compiling, Ncurses package must be installed.

Using the Terminal:  
`gcc source.c -o binaryfile -lncurses`

### In Codeblocks, go to Menu > Project > Build Options...  
    * In Linker settings > Link libraries:  
         + /usr/lib/libncurses.so

### Run using terminal:  
`./code5`
