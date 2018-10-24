/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_big_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 11:29:42 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/23 22:34:25 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"
#include <stdint.h>

void	tests_big_tests(void)
{
	unsigned char		**tab;
	int					i, ret;
	size_t				value;
	unsigned int		index;

	printf("\033[34;01mTESTS_BIG_TESTS\033[00m\n");
	tab = NULL;
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 1000);
	if (!tab)
	{
		printf("\033[31;01mError malloc tab[10000]\033[00m\n");
		return ;
	}
	i = 0;
	value = 0;
	value = rand() % MEDIUM;
	while (i < 100)
	{
		tab[i] = malloc(value);
		if (!tab[i])
			printf("\033[31;01mError malloc - i = %d / value = %zu\033[00m\n", i , value);
		i++;
		value = rand() % MEDIUM;
	}
	free(tab[0]);
	i = 0;
	index = rand() % 1000;
	if (index == 0)
		index = 1;
	value = rand();
	show_alloc_mem();
	printf("Valeur : value = %zu, %llu\n", value, SIZE_MAX);
	value = value / 4;
	printf("Valeur : value = %zu, index = %d\n", value, index);
	ret = index;
	while (i < 50)
	{
		tab[index] = realloc(tab[index], value);
		i++;
		value = rand() % MEDIUM;
		index = rand() % 1000;
		if (index == 0)
			index = 1;
	}
	i = 0;
	while (i < 1000)
	{
		if (ret == i)
		{
		//	print_header(((t_header *)tab[i]) - 1, "grrrr camesoule");
		//	print_define_zone();
		}
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("\033[33;01mshow alloc mem doit montrer qu'il y a aucune allocation en cours:\033[00m\n");
	show_alloc_mem();
}
