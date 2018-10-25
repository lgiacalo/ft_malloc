/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 00:01:39 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 07:07:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	print_size(t_header *header, size_t size)
{
	ft_putstr("\nDisplay new taken : h->len = ");
	ft_aputnbr((long long int)(header->len));
	ft_putstr(" / size = ");
	ft_aputnbr((long long int)(size));
	ft_putstr("\n");
}

int			ft_display_new_taken(t_zone *zone, t_header *header, size_t size)
{
	t_header	*new_header;
	t_header	*new_free;

	print_size(header, size);
	print_header(header, "display new taken");
	new_header = header;
	new_free = (t_header *)((char *)((t_header *)((header + 1))) + size);
	if ( (long long int)(header->len) - (long long int)size - (long long int)(16) <= 0)
		printf("PUTAIN DE MERDE header->len = %zu / size = %zu / sizeof(t_header) = %zu\n", header->len, size, sizeof(t_header)); //size negative ?!
	new_free->len = (size_t)(header->len) - size - (size_t)(sizeof(t_header));
	new_free->next = NULL;
	new_header->len = size;
	new_header->next = NULL;
	ft_hlst_add_malloc(&(zone->taken), new_header);
	ft_hlst_add_free(&(zone->free), new_free);
	return (1);
}

t_header	*ft_malloc_boucle_header(t_zone *zone, size_t size)
{
	t_header	*tmp;

	if (!zone)
		return (NULL);
	tmp = ft_hlst_extract_size(&(zone->free), size);
	print_header(tmp, "extract size pour malloc ts");
	if (!tmp)
		return (NULL);
	if (!ft_display_new_taken(zone, tmp, size))
		return (NULL);
	return (tmp);
}
