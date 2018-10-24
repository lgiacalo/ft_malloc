/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_complet_realloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:26:28 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/23 20:59:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_complet_realloc(int tiny, int medium)
{
	unsigned char		*ptr_1;
	unsigned char		*ptr_2;
	unsigned char		*ptr_3;

	printf("\033[34;01mTESTS_COMPET_REALLOC\033[00m\n");
	ptr_1 = malloc(tiny);
	if (!ptr_1)
		printf("\033[31;01mError malloc size tiny\033[00m\n");
	ptr_2 = realloc(ptr_1, medium);
	if (!ptr_2)
		printf("\033[31;01mError realloc, size medium\033[00m\n");
	else
		printf("\033[32;01mtest Realloc OK [%d]\033[00m\n", medium);
	printf("\033[33;01mFree doit echouer :\033[00m\n");
	free(ptr_1);
	printf("\033[33;01mshow alloc mem doit monter qu'il y a 1 alloc medium, size: %d\033[00m\n", medium);
	show_alloc_mem();
	ptr_3 = realloc(ptr_2, tiny + 2);
	if (!ptr_3)
		printf("\033[31;01mError realloc, size tiny + 2\033[00m\n");
	else
	{
		printf("\033[32;01mtest Realloc OK [%d]\033[00m\n", (tiny + 2));
	}
	show_alloc_mem();
	printf("\033[33;01mshow alloc mem doit monter qu'il y a 1 alloc, addresse inchange, size max : %d, size min:  %d \033[00m\n", medium, tiny + 2);
	show_alloc_mem();
	free(ptr_3);
	printf("\033[33;01mshow alloc mem doit monter qu'il y a aucune allocation en cours:\033[00m\n");
	show_alloc_mem();
}
