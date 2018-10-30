/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:14:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 20:46:34 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env			g_e = {NULL, NULL, NULL};

t_env			*env(void)
{
	return (&g_e);
}

size_t			ft_align(size_t size, int multiple)
{
	size_t tmp;

	tmp = size;
	if (!!(size % multiple))
		tmp = (size / multiple) * multiple + multiple;
	return (tmp);
}

static t_header	*ft_search_header_with_adr(t_header *first, void *ptr)
{
	t_header	*header;

	if (!first || !ptr)
		return (NULL);
	header = first;
	while (header)
	{
		if ((char *)ptr == (char *)header + ft_align(sizeof(t_header), 16))
			return (header);
		header = header->next;
	}
	return (NULL);
}

static t_zone	*ft_search_zone_with_adr(t_zone *first, void *ptr)
{
	t_zone	*zone;

	if (!first || !ptr)
		return (NULL);
	zone = first;
	while (zone)
	{
		if (ft_search_header_with_adr(zone->taken, ptr))
			return (zone);
		zone = zone->next_zone;
	}
	return (NULL);
}


int				ft_verif_adr_ptr(void *ptr)
{
	t_env	*e;

	e = env();
	if (ft_search_zone_with_adr(e->tiny, ptr)
			|| ft_search_zone_with_adr(e->small, ptr)
			|| ft_search_header_with_adr(e->large, ptr))
		return (1);
	return (0);
}
