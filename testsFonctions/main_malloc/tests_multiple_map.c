/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_multiple_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:24:04 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/03/12 15:00:15 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_multiple_map(int tiny)
{
	int					fd;
	int					save;
	int					i;
	unsigned char		**tab;

	i = 0;
	printf("\033[34;01mTESTS_MULTIPLE_MAP\033[00m\n");
	tab = malloc(sizeof(unsigned char *) * 1200);
	if (!tab)
		printf("\033[31;01mError malloc unsigned char* X 600\033[00m\n");
	while (i < 1200)
	{
		tab[i] = malloc(tiny);
		if (!tab[i])
		{
			printf("\033[31;01mError malloc size tiny'\033[00m\n");
			return ;
		}
		++i;
	}
	i = 300;
	while (i < 500)
	{
		free(tab[i]);
		++i;
	}
	i = 1000;
	while (i < 1200)
		free(tab[i++]);
	i = 0;
	while (i < 200)
		free(tab[i++]);
	save = dup(1);
	fd = open("tmp/tests_multiple_map.check", O_CREAT | O_TRUNC | O_RDWR, 000777);
	printf("\033[33;01mEtat de show_alloc_mem apres suppression d'une map au milieu, a la fin et au debut groupe (tiny): \033[00m\n");
	printf("\033[33;01mdans le fichier tmp/tests_multiple_map.check\033[00m\n");
	dup2(fd, 1);
	show_alloc_mem();
	dup2(save, 1);
	i = 200;
	while (i < 300)
		free(tab[i++]);
	i = 500;
	while (i < 1000)
		free(tab[i++]);
	free(tab);
	printf("\033[33;01mshow alloc mem doit montrer qu'il n'y a pas d'allocation en cours: \033[00m\n");
	show_alloc_mem();
	close(fd);
}
