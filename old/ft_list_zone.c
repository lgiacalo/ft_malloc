/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_zone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:50:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/18 21:31:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_link_maillon_zone(t_zone **first, t_zone *zone)
{
	t_env	*e;
	t_zone	*tp;
	t_zone	**tmp;

	e = env();
	tmp = first;
	if (*tmp)
	{
		tp = *tmp;
		while (tp->next_zone)
			tp = tp->next_zone;
		tp->next_zone = zone;
	}
	else
		*tmp = zone;
}

t_zone	*ft_extract_maillon_zone(t_zone **first, t_zone *zone)
{
	t_ret ret;

	if (!first || !(*first))
		return (NULL);
	ret = ft_search_maillon_zone(*(first), zone);
	if ((*first) == ret.suiv)
		*first = ZONE_NEXT(ret.suiv);
	else if (ret.suiv)
	{
		ZONE_NEXT(ret.prev) = ZONE_NEXT(ret.suiv);
		ZONE_NEXT(ret.suiv) = NULL;
	}
	return (ret.suiv);
}

t_ret	ft_search_maillon_zone(t_zone *first, t_zone *s)
{
	t_ret	ret;

	ft_init_struct_ret(&ret, NULL);
	if (!s || !first)
		return (ret);
	ret.prev = (void *)first;
	ret.suiv = (void *)first;
	while (ret.suiv)
	{
		if (ft_same_adr((void *)s, ret.suiv))
			break ;
		ret.prev = ret.suiv;
		ret.suiv = ZONE_NEXT(ret.suiv);
	}
	return (ret);
}

int		ft_zone_is_empty(t_zone *zone)
{
	t_header	*tmp;

	if (!zone)
		return (0);
	tmp = zone->taken;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->len > 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
