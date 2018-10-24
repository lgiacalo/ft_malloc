#!/bin/sh
make re -C ../depot/
gcc -o test0 test0.c
#/usr/bin/time -l ./test0
gcc -o test1 test1.c
#/usr/bin/time -l ./test1
gcc -o test2 test2.c
#gcc -o test3 test3.c
#gcc -o test3++ test3++.c
#gcc -o test_error test_error.c
#gcc -o test_show_alloc test_show_alloc.c -L../depot/ -lft_malloc
export DYLD_LIBRARY_PATH='../depot/'
export DYLD_INSERT_LIBRARIES='../depot/libft_malloc.so'
export DYLD_FORCE_FLAT_NAMESPACE='1'
/usr/bin/time -l ./test0
/usr/bin/time -l ./test1
/usr/bin/time -l ./test2
#./test3
#./test3++
#./test_error
#./test_show_alloc
./delete.sh
