rm -rf test
#gcc -o test testsFonctions/main.c
#gcc -o test testsFonctions/main_malloc/tests_all_map.c
#gcc -o test testsFonctions/main_malloc/tests_big_tests.c
#gcc -o test testsFonctions/main_malloc/tests_complet_map_large.c
#gcc -o test testsFonctions/main_malloc/tests_complet_map_medium.c
#gcc -g -o test testsFonctions/main_malloc/tests_complet_map_tiny.c testsFonctions/main_malloc/main_malloc.c
#gcc -o test testsFonctions/main_malloc/tests_complet_realloc.c 
#gcc -o test testsFonctions/main_malloc/test_corruption_memory.c 
#gcc -o test testsFonctions/main_malloc/tests_getrlimit.c
#gcc -o test testsFonctions/main_malloc/tests_multi_thread.c
#gcc -o test testsFonctions/main_malloc/tests_multiple_map.c
#gcc -o test testsFonctions/main_malloc/tests_simples_malloc.c 
#gcc testsFonctions/main_malloc/*


gcc -g -o test testsFonctions/main_malloc/main_malloc.c testsFonctions/main_malloc/tests_all_map.c testsFonctions/main_malloc/tests_big_tests.c testsFonctions/main_malloc/tests_complet_map_large.c testsFonctions/main_malloc/tests_complet_map_tiny.c testsFonctions/main_malloc/tests_complet_map_medium.c testsFonctions/main_malloc/tests_complet_realloc.c testsFonctions/main_malloc/tests_corruption_memory.c testsFonctions/main_malloc/tests_getrlimit.c testsFonctions/main_malloc/tests_multi_thread.c testsFonctions/main_malloc/tests_multiple_map.c testsFonctions/main_malloc/tests_simples_malloc.c


#gcc -g -o test testsFonctions/main.c
#gcc -g -o test testsFonctions/structlen.c

