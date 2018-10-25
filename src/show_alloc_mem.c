/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:10:05 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 04:43:31 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	print_mem(t_header *header)
{
	ft_putstr("0x");
	ft_putpnbr_base((unsigned long long int)(header + 1), "0123456789ABCDEF");
	ft_putstr(" - ");
	ft_putstr("0x");
	ft_putpnbr_base((unsigned long long int)(((char *)(header + 1))
				+ header->len), "0123456789ABCDEF");
	ft_putstr(" : ");
	ft_aputnbr(header->len);
	ft_putstr(" octets\n");
	return (header->len);
}

static int	boucle_header(t_header *header, void *max, char *str)
{
	int	i;

	if (!header)
		return (0);
	i = 0;
	while (header)
	{
		if (str && header)
		{
			ft_putstr(str);
			ft_putpnbr_base((unsigned long long int)header, "0123456789ABCDEF");
			ft_putstr("\n");
		}
		i += print_mem(header);
		if (max && (void *)((HEADER_NEXT(header) + sizeof(t_header))) > max)
			return (i);
		header = HEADER_NEXT(header);
	}
	return (i);
}

static int	boucle_zone(t_zone *zone, char *str)
{
	int	i;

	i = 0;
	if (!zone || !(zone->taken))
		return (0);
	while (zone)
	{
		if (str && zone->taken)
		{
			ft_putstr(str);
			ft_putpnbr_base((unsigned long long int)(zone + 1),
					"0123456789ABCDEF");
			ft_putstr("\n");
		}
		i += boucle_header(zone->taken, ZONE_MAILLON_NEXT(zone), NULL);
		zone = ZONE_NEXT(zone);
	}
	return (i);
}

static int	boucle_zone_free(t_zone *zone, char *str)
{
	int	i;

	i = 0;
	if (!zone || !(zone->free))
		return (0);
	while (zone)
	{
		if (str && zone->free)
		{
			ft_putstr(str);
			ft_putpnbr_base((unsigned long long int)(zone + 1),
					"0123456789ABCDEF");
			ft_putstr("\n");
		}
		i += boucle_header(zone->free, ZONE_MAILLON_NEXT(zone), NULL);
		zone = ZONE_NEXT(zone);
	}
	return (i);
}

void 	show_free_mem(void)
{
	t_env	*e;
	int		total;

	e = env();
	total = 0;
	if (e->tiny)
		total += boucle_zone_free(e->tiny, "TINY : 0x");
	if (e->small)
		total += boucle_zone_free(e->small, "SMALL : 0x");
	ft_putstr("Total : ");
	ft_aputnbr(total);
	ft_putstr(" octets libres\n");
}

void		show_alloc_mem(void)
{
	t_env	*e;
	int		total;

	e = env();
	total = 0;
	if (e->tiny)
		total += boucle_zone(e->tiny, "TINY : 0x");
	if (e->small)
		total += boucle_zone(e->small, "SMALL : 0x");
	if (e->large)
		total += boucle_header(e->large, NULL, "LARGE : 0x");
	ft_putstr("Total : ");
	ft_aputnbr(total);
	ft_putstr(" octets\n");
}
