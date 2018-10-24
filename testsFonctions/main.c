/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:50:00 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 00:57:13 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/resource.h>
#include "../include/malloc.h"

int main(void)
{

	printf("Valeur getpagesize() = %d \n", getpagesize());
	printf("1er appe => 0l\n\n\n");
	ft_malloc((size_t)0);
	show_alloc_mem();
	printf("2e appel => 42\n\n\n");
	ft_malloc((size_t)42);
	show_alloc_mem();
	printf("2e appel => 68\n\n\n");
	ft_malloc((size_t)68);
	show_alloc_mem();
	printf("3e appel => 300\n\n\n");
	ft_malloc((size_t)300);
	show_alloc_mem();
	printf("4e appel => 629\n\n\n");
	ft_malloc((size_t)629);
	show_alloc_mem();
	printf("5e appel => 1050\n\n\n");
	ft_malloc((size_t)1050);
	show_alloc_mem();
	printf("6e appel => 6048\n\n\n");
	ft_malloc((size_t)6048);
	show_alloc_mem();

/*
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");

	char **tab;
	int		i;

	tab = (char **)ft_malloc(sizeof(char *) * (100 + 1));
	i = 0;

	while (i < 100)
	{
		tab[i] = (char *)ft_malloc(sizeof(char ) * ((10 + i) + ((i % 2) ? -5 : +7)));
		i++;
	}
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");

	i = 0;
	while (i < 100)
	{
		if (!(i % 2))
			free(tab[i]);
		i++;
	}
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");
	free(tab[3]);
	free(tab[21]);
	free(tab[45]);
	free(tab[69]);
	free(tab[23]);
	free(tab[91]);
	free(tab[41]);
	free(tab[63]);
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");
	free(tab);
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");



	char	*str;
	char	*str2;

	str = (char *)ft_malloc(sizeof(char) * 2048);
	str2 = (char *)ft_malloc(sizeof(char) * 1032);

		show_alloc_mem();
		printf("\n");
		show_free_mem();
		printf("\n");
	free(str2);
		show_alloc_mem();
		printf("\n");
		show_free_mem();
		printf("\n");

	free(str);
		show_alloc_mem();
		printf("\n");
		show_free_mem();
		printf("\n");

	print_define_zone();
	printf("\n");


	char **t;

	t = (char **)ft_malloc(sizeof(char *) * (50 + 1));
	i = 0;

	while (i < 0)
	{
		t[i] = (char *)ft_malloc(sizeof(char ) * ((10 + i) + ((i % 2) ? -5 : +7)));
		i++;
	}
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");

	i = 0;
	while (i < 50)
	{
		if (!(i % 2))
			free(t[i]);
		i++;
	}
	
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");

	
	free(t[3]);
	free(t[6]);
	free(t[9]);
	free(t[12]);
	free(t[15]);
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");
	printf("\n");


	realloc(t[20], 5);
	realloc(t[5], 6);
	realloc(t[10], 7);
	printf("\n");

	printf("\n");
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");

	
	free(t);
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");


	t = (char **)ft_malloc(sizeof(char *) * (500 + 1));
	i = 0;

	while (i < 2)
	{
		t[i] = (char *)ft_malloc(sizeof(char ) * (i % 2) ? 2000 : 1500);
		i++;
	}
	while (i < 500)
	{
		//t[i] = (char *)ft_malloc(sizeof(char ) * ((10 + i) + ((i % 2) ? -5 : +7)));
		t[i] = (char *)ft_malloc(sizeof(char ) * (120));
		i++;
	}

	printf("MERDEMERDE\n");
	printf("\n");
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");
	printf("\n");

	free(t[0]);
	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");
	printf("\n");

	void *test = realloc(t[1], 200);
	print_header(((t_header *)test) - 1, "verif");

	show_alloc_mem();
	printf("\n");
	show_free_mem();
	printf("\n");
*/

	return (0);
}
