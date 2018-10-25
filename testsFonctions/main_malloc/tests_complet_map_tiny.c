/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_complet_map_tiny.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:03:11 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/25 06:26:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_complet_map_tiny(int tiny)
{
	FILE			*fd;
	int				i;
	int				value;
	unsigned char	**tab;

	printf("\033[34;01mTESTS_COMPLET_MAP_TINY\033[00m\n");
	fd = fopen("tmp/tests_complet_map_tiny.check", "w+");
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 100);
	if (!tab)
	{
		fprintf(fd, "\033[31;01mError malloc 100 * 'sizeof(unsigned char *)'\033[00m\n");
		return ;
	}
	i = 0;
	value = rand() % tiny + 1;
	while (i < 100)
	{
		if (i == 42)
			value = 1;
		fprintf(fd, "value: %d, i: %d\n", value, i);
		tab[i] = malloc(sizeof(char) * (value));
		if (!tab[i])
			fprintf(fd, "\033[31;01mError malloc size %d, nbr alloc: %d\033[00m\n", value, i);
		if (value != 1)
		{
			memset(tab[i], 'b', value);
			tab[i][value - 1] = '\0';
			tab[i][0] = 'a';
			tab[i][value - 2] = 'a';
		}
		i++;
		value = rand() % tiny + 1;
	}
	i = 0;
	while (i < 100)
	{
		fprintf(fd, "Alloc num: %d: %s\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("\033[33;01mshow alloc mem doit montrer qu'il y a aucune allocation en cours:\033[00m\n");
	show_alloc_mem();
	fclose(fd);
}

