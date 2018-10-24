/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_all_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:08:56 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/23 19:39:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_all_map(int tiny, int medium, int show_hex)
{
	int				fd;
	int				fd_ex;
	int				save;
	int				i;
	size_t			value;
	unsigned char	**tab;

	printf("\033[34;01mTESTS_ALL_MAP\033[00m\n");
	save = dup(1);
	fd = open("tmp/resultat_tests_all_map.check", O_CREAT | O_TRUNC | O_RDWR, 000777);
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 10000);
	if (!tab)
	{
		printf("\033[31;01mError malloc 10000 * 'sizeof(unsigned char *)'\033[00m\n");
		return ;
	}
	i = 0;
	value = rand() % tiny + 1;
	while (i < 5000)
	{
		tab[i] = malloc(sizeof(char) * (value));
		if (!tab[i])
			printf("\033[31;01mError malloc size %ld, nbr alloc: %d\033[00m\n", value, i);
		i++;
		value = rand() % tiny + 1;
	}
	value = (rand() % medium) + 1;
	if (value <= (size_t)tiny)
		value += tiny;
	while (i < 9900)
	{
		tab[i] = malloc(sizeof(char) * (value));
		if (!tab[i])
			printf("\033[31;01mError malloc size %ld, nbr alloc: %d\033[00m\n", value, i);
		i++;
		value = (rand() % medium) + 1;
		if (value <= (size_t)tiny)
			value += tiny;
	}
	value = rand() % 20000 + 1;
	if (value <= (size_t)medium)
		value += medium;
	while (i < 10000)
	{
		tab[i] = malloc(sizeof(char) * (value));
		if (!tab[i])
		{
			printf("\033[31;01mError malloc size %ld, nbr alloc: %d\033[00m\n", value, i);
			break ;
		}
		i++;
		value = rand() % 20000 + 1;
		if (value <= (size_t)medium)
			value += medium;
	}
	if (show_hex == 0)
	{
		printf("\033[33;01mShow alloc mem in file 'resultat_tests_all_map.check'... \033[00m\n");
		dup2(fd, 1);
		show_alloc_mem();
	}
	else if (show_hex == 1)
	{
		fd_ex = open("tmp/resultat_tests_all_map_ex.check", O_CREAT | O_TRUNC | O_RDWR, 000777);
		printf("\033[33;01mShow alloc mem in file 'resultat_tests_all_map.check'... \033[00m\n");
		dup2(fd, 1);
		show_alloc_mem();
		dup2(save, 1);
		printf("\033[33;01mShow alloc mem_ex in file 'resultat_tests_all_map_ex.check'... \033[00m\n");
		dup2(fd_ex, 1);
		show_alloc_mem();
		close(fd_ex);
	}
	close(fd);
	dup2(save, 1);
	i = 0;
	while (i < 10000)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("\033[33;01mShow alloc mem doit montrer qu'il y a aucune allocation en cours: \033[00m\n");
	show_alloc_mem();
	return ;
}

