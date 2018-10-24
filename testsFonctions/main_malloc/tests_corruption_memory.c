/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_corruption_memory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 11:06:10 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/23 20:33:45 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_corruption_memory(int tiny, int medium)
{
	unsigned char	**tab;
	unsigned char	*ptr;
	int				i;

	(void)tiny;
	printf("\033[34;01mTESTS_ECRITURE_BEFORE_ALLOC\033[00m\n");
	i = 0;
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 100);
	while (i < 100)
	{
		tab[i] = malloc(medium);
		show_alloc_mem();
		i++;
	}
	i = 42;
	ptr = tab[41];
	ptr -= medium * 10;
	memset(ptr, 'H', medium * 20 + 24);
	printf("\033[33;01mFree doit retourner une erreur mais pas un segfault.\033[00m\n");
	free(tab[41]);
	printf("\033[33;01mRealloc doit pas un segfault.\033[00m\n");
	tab[41] = realloc(tab[41], tiny);
	printf("\033[33;01mMalloc doit pas segfault, erreur resonne:\033[00m\n");
	tab[42] = malloc(medium);
}
