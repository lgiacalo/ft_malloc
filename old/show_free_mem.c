/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_free_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:25:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 19:05:06 by lgiacalo         ###   ########.fr       */
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

static int	boucle_header(t_zone *zone, t_header *header, char *str)
{
	int			i;

	i = 0;
	if (!header)
		return (0);
	while (header)
	{
		if (header == ((ft_search_maillon_header(zone->free, header,
							0, ft_same_adr)).suiv))
			i += print_mem(header);
		header = (t_header *)(((char *)(header + 1)) + header->len);
		if (((char *)header) > (((char *)(zone + 1)) + zone->len_zone))
			break ;
	}
	if (str && i != 0)
	{
		ft_putstr(str);
		ft_putpnbr_base((unsigned long long int)header, "0123456789ABCDEF");
		ft_putstr("\n");
	}
	return (i);
}

static int	boucle_zone(t_zone *zone, char *str)
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
		i += boucle_header(zone, (t_header *)(zone + 1), NULL);
		zone = ZONE_NEXT(zone);
	}
	return (i);
}

void		show_free_mem(void)
{
	t_env	*e;
	int		total;

	e = env();
	total = 0;
	ft_putstr("\n---- Zones disponibles ----\n");
	if (e->tiny)
		total += boucle_zone(e->tiny, "TINY : 0x");
	if (e->small)
		total += boucle_zone(e->small, "SMALL : 0x");
	ft_putstr("Total : ");
	ft_aputnbr(total);
	ft_putstr(" octets libres\n");
}
