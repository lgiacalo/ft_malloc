/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_multi_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 14:59:59 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/25 05:19:13 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

static void			ft_free2(unsigned char **tab)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		free(tab[i]);
		++i;
	}
}

static void			*function_1(void *medium)
{
	unsigned char	**tab;
	int				i;
	int				value;
	int				med;

	med = *(int *)medium;
	i = 0;
	value = rand() % med + 1;
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 1000);
	if (!tab)
		printf("\033[31;01mError malloc !\033[00m\n");
	while (i < 1000)
	{
		tab[i] = malloc(sizeof(char) * value);
		if (!tab[i])
			printf("\033[31;01mError malloc !\033[00m\n");
		++i;
		value = rand() % med + 1;
	}
	sleep(10);
	ft_free2(tab);
	return (NULL);
}

static void			*function_2(void *medium)
{
	unsigned char	**tab;
	int				i;
	int				value;
	int				med;

	med = *(int *)medium;
	i = 0;
	value = rand() % med + 1;
	tab = (unsigned char **)malloc(sizeof(unsigned char *) * 1000);
	if (!tab)
		printf("\033[31;01mError malloc !\033[00m\n");
	while (i < 1000)
	{
		tab[i] = malloc(sizeof(char) * value);
		if (!tab[i])
			printf("\033[31;01mError malloc !\033[00m\n");
		++i;
		value = rand() % med + 1;
	}
	sleep(10);
	ft_free2(tab);
	return (NULL);
}

static void			*function_3(void *nothing)
{
	(void)nothing;

	show_alloc_mem();
	return (NULL);
}

void		tests_multi_thread(int tiny, int medium)
{
	pthread_t		pt1;
	pthread_t		pt2;
	pthread_t		pt3;
	pthread_t		pt4;
	int				fd;
	int				save;

	save = dup(1);
	fd = open("tmp/tests_multi_thread.check", O_CREAT | O_TRUNC | O_RDWR, 000777);
	printf("\033[34;01mTESTS_MULTI_THREAD\033[00m\n");
	printf("\033[33;01mDans le fichier tmp/tests_multi_thread.check, consulter les deux appel a show_alloc_mem\033[00m\n");
	printf("\033[33;01mIls ne doivent pas s'entremeler, le premier appel est beaucoup plus court que le deuxieme.\033[00m\n");
	(void)tiny;
	if (pthread_create(&pt1, NULL, function_1, &medium) < 0)
	{
		printf("\033[31;01mError on ceation thread number 1\033[00m\n");
		exit(1);
	}
	if (pthread_create(&pt2, NULL, function_2, &medium) < 0)
	{
		printf("\033[31;01mError on ceation thread number 2\033[00m\n");
		exit(1);
	}
	dup2(fd, 1);
	if (pthread_create(&pt3, NULL, function_3, NULL) < 0)
	{
		printf("\033[31;01mError on ceation thread number 3\033[00m\n");
		exit(1);
	}
	sleep(5);
	if (pthread_create(&pt4, NULL, function_3, NULL) < 0)
	{
		printf("\033[31;01mError on ceation thread number 3\033[00m\n");
		exit(1);
	}
	sleep(3);
	dup2(save, 1);
}
