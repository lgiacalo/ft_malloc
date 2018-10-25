/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 00:01:39 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 06:18:03 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			ft_display_new_taken(t_zone *zone, t_header *header, size_t size)
{
	t_header	*new_header;
	t_header	*new_free;

	new_header = header;
	if (header->len > (size_t)500000)
		printf("size 1 : %zu\n", header->len);
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
//	print_header(tmp, "extract\n");
	if (!tmp)
		return (NULL);
	if (!ft_display_new_taken(zone, tmp, size))
		return (NULL);
	return (tmp);
}
