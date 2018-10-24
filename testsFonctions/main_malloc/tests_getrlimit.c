/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_getrlimit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 13:44:54 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/03/11 14:28:24 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "main_malloc.h"

void			tests_getrlimit(void)
{
	unsigned char		*ptr;
	size_t				value;

	printf("\033[34;01mTESTS_GETRLIMIT\033[00m\n");
	value = ULONG_MAX;
	printf("\033[33;01mGetRLimit ne devrait pas permettre le malloc avec le max d'un size_t:\033[00m\n");
	ptr = malloc(value);
	if (!ptr)
		printf("\033[32;01mGetRLimit refuse, test OK\033[00m\n");
	else
	{
		printf("\033[31;01mGetRlimit accepte, test ko\033[00m\n");
		free(ptr);
	}
	value = value / 4;
	printf("\033[33;01mMMAP devrait refuser cette allocation (ULONG_MAX / 4):\033[00m\n");
	ptr = malloc(value);
	if (ptr)
	{
		printf("\033[31;01mMMAP refuse, test KO\033[00m\n");
		free(ptr);
	}
	else
		printf("\033[32;01mMMAP refuse, test OK\033[00m\n");
	value = 0;
	printf("\033[33;01mMalloc devrait accepter une allocation de 0, et fournir au minimum 1 de taille:.\033[00m\n");
	ptr = malloc(value);
	if (ptr)
	{
		printf("\033[32;01mMalloc OK\033[00m\n");
		printf("\033[33;01mshow alloc mem doit monter qu'il y a une seule allocation de minimum 1: \033[00m\n");
		show_alloc_mem();
		free(ptr);
	}
	else
		printf("\033[31;01mMalloc KO size == 0\033[00m\n");
}
