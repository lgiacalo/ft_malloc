/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_simples_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:00:37 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/23 19:44:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

void		tests_simples_malloc(void)
{
	size_t			value;
	unsigned char	*ptr;

	printf("\033[34;01mTESTS_SIMPLES_MALLOC\033[00m\n");
	value = 8;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '8'\033[00m\n");
	bzero(ptr, 8);
	memcpy(ptr, "Bonjour", 7);
	printf("\033[32;01mMalloc ok, size '9': %s\033[00m\n", ptr);
	free(ptr); // next
	value = 1000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '1000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 1000\033[00m\n");
		free(ptr);
	} // next
	value = 2000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '2000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 2000\033[00m\n");
		free(ptr);
	} // next
	value = 3000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '3000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 3000\033[00m\n");
		free(ptr);
	} // next
	value = 4000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '4000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 4000\033[00m\n");
		free(ptr);
	} // next
	value = 5000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '5000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 5000\033[00m\n");
		free(ptr);
	} // next
	value = 6000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '6000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 6000\033[00m\n");
		free(ptr);
	} // next
	value = 7000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '7000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 7000\033[00m\n");
		free(ptr);
	} // next
	value = 8000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '8000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 8000\033[00m\n");
		free(ptr);
	} // next
	value = 42000;
	ptr = malloc(value);
	if (!ptr)
		printf("\033[31;01mError malloc size '42000'\033[00m\n");
	else
	{
		printf("\033[32;01mMalloc ok, size 42000\033[00m\n");
		free(ptr);
	} // next
//
// Decouper pour tester le max d'un site_t
// Dans la fonction getrlimit test, tester l'echec de mmap comme suit ici !
	value = 0;
	value -= 1;
	value = value / 2;
	value -= value / 2;
	printf("\033[33;01mMalloc doit echouer.\033[00m\n");
	ptr = malloc(value);

	if (!ptr)
		printf("\033[32;01mOk malloc refuse 'max size_t'\033[00m\n");
	else
	{
		printf("\033[31;01mError malloc accept alloc size max_size_t\033[00m\n");
		free(ptr);
	}
	show_alloc_mem();
}

