/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:14:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 22:01:39 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env			g_e = {NULL, NULL, NULL};

t_env			*env(void)
{
	return (&g_e);
}

size_t			ft_align_16(size_t size)
{
	size_t tmp;

	tmp = size;
	if (size == 0)
		return (16);
	if (!!(size % 16))
		tmp = (size / 16) * 16 + 16;
	return (tmp);
}

size_t			ft_align_page(size_t size)
{
	size_t tmp;
	size_t page;

	page = getpagesize();
	tmp = size;
	if (!!(size % page))
		tmp = (size / page) * page + page;
	return (tmp);


}

static t_header	*ft_search_header_with_adr(t_header *first, void *ptr)
{
	if (!first || !ptr)
		return (NULL);
	while (first)
	{
		if ((char *)first + ft_align_16(sizeof(t_header)) == (char *)ptr)
			return (first);
		first = first->next;
	}
	return (NULL);
}

static t_zone	*ft_search_zone_with_adr(t_zone *first, void *ptr)
{
	if (!first || !ptr)
		return (NULL);
	while (first)
	{
		if (ft_search_header_with_adr(first->taken, ptr))
			return (first);
		first = first->next_zone;
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
