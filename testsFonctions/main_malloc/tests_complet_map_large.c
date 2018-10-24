/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_complet_map_large.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:08:07 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/03/11 09:23:27 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_complet_map_large(int medium)
{
	int				i;
	size_t			value;
	unsigned char	**tab;

	printf("\033[34;01mTESTS_COMPLET_MAP_LARGE\033[00m\n");
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 100);
	if (!tab)
	{
		printf("\033[31;01mError malloc 100 * 'sizeof(unsigned char *)'\033[00m\n");
		return ;
	}
	i = 0;
	value = rand() + 1;
	if (value <= (size_t)medium)
		value += medium;
	while (i < 20)
	{
		printf("value: %ld\n", value);
		tab[i] = malloc(sizeof(char) * (value));
		if (!tab[i])
		{
			printf("\033[31;01mError malloc size %ld, nbr alloc: %d\033[00m\n", value, i);
			break ;
		}
		i++;
		value = rand() + 1;
		if (value <= (size_t)medium)
			value += medium;
	}
	i = 0;
	while (i < 20)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("\033[33;01mshow alloc mem doit monter qu'il y a aucune allocation en cours:\033[00m\n");
	show_alloc_mem();
}

