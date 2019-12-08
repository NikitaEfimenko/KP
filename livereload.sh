echo "build...";
find . -name '*.c' | 
entr sh -c 'make && echo "*** success compile! ***\n" && ./a.out'