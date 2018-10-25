/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 22:03:31 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 22:58:45 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void	ft_print_int(char *str1, long long int nbr, char *str2)
{
	ft_putstr(str1);
	ft_aputnbr(nbr);
	ft_putstr(str2);
}

void	ft_print_int16(char *str1, unsigned long long int nbr, char *str2)
{
	ft_putstr(str1);
	ft_putstr("0x");
	ft_putpnbr_base(nbr, "0123456789ABCDEF");
	ft_putstr(str2);
}

void	ft_print_str(char *str1, char *str2, char *str3)
{
	ft_putstr(str1);
	ft_putstr(str2);
	ft_putstr(str3);
}

void	print_map(t_zone *zone)
{
	t_zone		*z;
	t_header	*take;
	t_header	*freee;

	z = zone;
	while (zone)
	{
		print_zone(zone, NULL);
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
		ft_putstr("Header n'existe pas !!!\n");
		return ;
	}
	ft_print_str("\n--------------- LIST HEADER: ", str, "------------------\n");
	while (header)
	{
		print_header(header, "");
		header = header->next;
		i++;
	}
	ft_putstr("--------------- FIN LIST------------------\n\n\n");
}

void	print_header(t_header *header, char *str)
{
	if (!header)
	{
		ft_putstr("Header n'existe pas !!!\n");
		return ;
	}
	ft_print_str("---------- HEADER ", str, " ----------\n");
	ft_print_int16("Adresse :\t", (unsigned long long int)(header), "\n");
	ft_print_int("Taille :\t", (long long int)(header->len), "\n");
	ft_print_int16("Adr next :\t", (unsigned long long int)(header->next), "\n");
	ft_putstr("-------------------------------\n");

}

void	print_zone(t_zone *zone, char *str)
{
	if (!zone)
	{
		ft_putstr("Zone n'existe pas !!!\n'");
		return ;
	}
	ft_print_str("---------- ZONE ", str, " ----------\n");
	ft_print_int16("Adresse :\t", (unsigned long long int)(zone), "\n");
	ft_print_int("Taille :\t", (long long int)(zone->len_zone), "\n");
	ft_print_int16("Adr taken :\t", (unsigned long long int)(zone->taken), "\n");
	ft_print_int16("Adr free :\t", (unsigned long long int)(zone->free), "\n");
	ft_print_int16("Adr next zone :\t", (unsigned long long int)(zone->next_zone), "\n");
	ft_putstr("----------------------------------------------\n\n");
}

void	print_define_zone(void)
{
	ft_putstr("\n ------- DEFINE -------\n");
	ft_print_int("PAGESIZE :\t\t", (long long int)PAGESIZE, " \n");
	ft_print_int("TINY_ZONE :\t\t", (long long int)TINY_ZONE, " \n");
	ft_print_int("TINY_MAX_ALLOC :\t", (long long int)TINY_MAX_ALLOC, " \n");
	ft_print_int("SMALL_ZONE :\t\t", (long long int)SMALL_ZONE, " \n");
	ft_print_int("SMAL_MAX_ALLOC :\t", (long long int)SMALL_MAX_ALLOC, " \n");
}

void	print_env(void)
{
	t_env	*e;

	e = env();
	if (!e)
	{
		printf("Env n'existe pas !!!\n'");
		return ;
	}
	ft_putstr("---------------- ENV ----------------\n");
	ft_print_int16("Adresse TINY :\t", (unsigned long long int)(e->tiny), " \n");
	ft_print_int16("Adresse SMALL :\t", (unsigned long long int)(e->small), " \n");
	ft_print_int16("Adresse LARGE :\t", (unsigned long long int)(e->large), " \n");
	ft_putstr("-------------------------------------\n\n");
}
