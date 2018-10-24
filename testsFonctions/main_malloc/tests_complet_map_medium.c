/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_complet_map_medium.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:07:18 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/03/11 13:42:52 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_complet_map_medium(int medium, int tiny)
{
	FILE			*fd;
	int				i;
	int				value;
	unsigned char	**tab;

	printf("\033[34;01mTESTS_COMPLET_MAP_MEDIUM\033[00m\n");
	fd = fopen("tmp/tests_complet_map_medium.check", "w+");
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 100);
	if (!tab)
	{
		fprintf(fd, "\033[31;01mError malloc 100 * 'sizeof(unsigned char *)'\033[00m\n");
		return ;
	}
	i = 0;
	value = (rand() % medium) + 1;
	if (value <= tiny)
		value += tiny;
	while (i < 100)
	{
		tab[i] = malloc(sizeof(char) * (value));
		if (!tab[i])
			fprintf(fd, "\033[31;01mError malloc size %d, nbr alloc: %d\033[00m\n", value, i);
		memset(tab[i], 'b', value);
		tab[i][value - 1] = '\0';
		tab[i][0] = 'a';
		tab[i][value - 2] = 'a';
		i++;
		value = (rand() % medium) + 1;
		if (value <= tiny)
			value += tiny;
	}
	i = 0;
	while (i < 100)
	{
		fprintf(fd, "Alloc num: %d: %s\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("\033[33;01mshow alloc mem doit monter qu'il y a aucune allocation en cours: \033[00m\n");
	show_alloc_mem();
	fclose(fd);
}

