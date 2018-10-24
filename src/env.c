/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:14:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 23:14:35 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env			g_e = {NULL, NULL, NULL};

t_env			*env(void)
{
	return (&g_e);
}

static t_header	*ft_search_header_with_adr(t_header *first, void *ptr, void *max)
{
	if (!first || !ptr)
		return (NULL);
	while (first)
	{
		if (first == (ptr - sizeof(t_header)))
			return (first);
		if ( max && (void *)HEADER_NEXT(first) >= max)
			return (NULL);
		first = HEADER_NEXT(first);
	}
	return (NULL);
}

static t_zone	*ft_search_zone_with_adr(t_zone *first, void *ptr)
{
	if (!first || !ptr)
		return (NULL);
	while (first)
	{
		if (((((void *)(first->taken) + sizeof(t_header)) <= ptr)
			&& ((void *)ptr < (void *)ZONE_MAILLON_NEXT(first))))
			if (ft_search_header_with_adr(first->taken, ptr, (void *)ZONE_MAILLON_NEXT(first)))
				return (first);
		first = ZONE_NEXT(first);
	}
	return (NULL);
}


int	ft_verif_adr_ptr(void *ptr)
{
	t_env	*e;

	e = env();
	if (ft_search_zone_with_adr(e->tiny, ptr)
			|| ft_search_zone_with_adr(e->small, ptr)
			|| ft_search_header_with_adr(e->large, ptr, NULL))
		return (1);
	return (0);

}
