/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 00:01:39 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 05:11:39 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			ft_display_new_taken(t_zone *zone, t_header *header, size_t size)
{
	t_header	*new_header;
	t_header	*new_free;

	new_header = header;
	new_free = (t_header *)((char *)((t_header *)((header + 1))) + size);
	new_free->len = header->len - size - sizeof(t_header);
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
	t_header	*new_free;

	if (!zone)
		return (NULL);
	tmp = ft_hlst_extract_size(&(zone->free), size, ft_tri_size_more_header);
	if (!tmp)
		return (NULL);
	if (!ft_display_new_taken(zone, tmp, size))
		return (NULL);
	return (tmp);
}
