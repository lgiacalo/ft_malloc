# ft_malloc

- Eviter dutiliser la lib - trop lourd !!
- test --> gbersac
- voir livre linux victor
- malloc mac os !! et non linux
	et regarder les tailles des zones memoires
- linkage utilise le malloc ! 
- regarder les constructeurs et destructeur en C

- make 
- ./execTests.sh
- ./run.sh ./test  <=== linkage 

- Retirer option debug dans Makefile
- Retirer les ft devant fonction malloc, free, etc
- attention overflow pour calloc !!
- remettre flags dans Makefile



TEst with term : 
-> compiler
-> exec run sans @

toujours verifier si les adresses font parties des map

probleme avec tri_len
alignement 16octets
revoir test getrlimit();
verif max danx les boucles listes 
segfault avec vim ?

env DYLD_LIBRARY_PATH=./ DYLD_INSERT_LIBRARIES="./libft_malloc.so" DYLD_FORCE_FLAT_NAMESPACE=1

debug with gdb : -g3 -ggdb3
