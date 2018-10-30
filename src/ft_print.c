/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:39:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 21:26:20 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"



void	print_map(t_zone *zone)
{
	t_zone		*z;
	t_header	*take;
	t_header	*freee;

	z = zone;
	while (zone)
	{
		print_zone(zone);
		take = zone->taken;
		print_list_header(take, "TAKEN");
		freee = zone->free;
		print_list_header(freee, "FREE");
		zone = zone->next_zone;
	}
}

void	print_list_header(t_header *header, char *str)
{
	int	i;

	i = 0;
	if (!header)
	{
		printf("Header n'existe pas !!!\n");
		return ;
	}
	printf("\n--------------- LIST HEADER: %s ------------------\n", str);
	while (header)
	{
		print_header(header, "");
		header = header->next;
		i++;
	}
}

void	print_header(t_header *header, char *str)
{
	if (!header)
	{
		printf("Header n'existe pas !!!\n");
		return ;
	}
	printf("---------- HEADER %s ----------\n", str);
	printf("Adresse :\t%p : %ld\n", header, (long int)header);
	printf("Taille :\t%zu\n", header->len);
	printf("Adr next :\t%p\n", header->next);
	printf("-------------------------------\n");
}

void	print_zone(t_zone *zone)
{
	if (!zone)
	{
		printf("Zone n'existe pas !!!\n'");
		return ;
	}
	printf("--------------------- ZONE -------------------\n");
	printf("Adresse :\t%p : %ld\n", zone, (long int)zone);
	printf("Taille :\t%zu\n", zone->len_zone);
	printf("Adr taken :\t%p\n", zone->taken);
	printf("Adr free :\t%p\n", zone->free);
	printf("Adr next zone:\t%p\n", zone->next_zone);
	printf("----------------------------------------------\n\n");
}

void	print_env(t_env *env)
{
	if (!env)
	{
		printf("Env n'existe pas !!!\n'");
		return ;
	}
	printf("---------------- ENV ----------------\n");
	printf("Adresse TINY :\t%p\n", env->tiny);
	printf("Adresse SMALL :\t%p\n", env->small);
	printf("Adresse LARGE :\t%p\n", env->large);
	printf("-------------------------------------\n\n");
}
