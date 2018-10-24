/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:51:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/21 21:54:25 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_header	*ft_extract_header_zone(t_zone **first, t_header *ptr)
{
	t_zone		*tmp_zone;
	t_header	*tmp_header;

	if (!first || !(*first) || !ptr)
		return (NULL);
	tmp_zone = *first;
	tmp_header = NULL;
	while (tmp_zone)
	{
		if ((tmp_header = ft_extract_maillon_header(&(tmp_zone->taken),
						ptr, ft_same_adr)))
			break ;
		tmp_zone = ZONE_NEXT(tmp_zone);
	}
	if (tmp_header)
	{
		ft_link_maillon_header(&(tmp_zone)->free, tmp_header, ft_tri_len);
		ft_fusion_maillon_header(&(tmp_zone)->free, tmp_header);
	}
	return (NULL);
}

/*
**	Search la zone a laquelle appartient ptr, et la renvoit dans ret.new
**		prev : maillon precedent de ptr
**		suiv : ptr car ft_same_adr
*/

t_ret		ft_search_header_zone(t_zone *first, t_header *ptr)
{
	t_ret	ret;

	ft_init_struct_ret(&ret, NULL);
	if (!first || !ptr)
		return (ret);
	while (first)
	{
		ft_init_struct_ret(&ret, NULL);
		ret = ft_search_maillon_header(first->taken, ptr, 0, ft_same_adr);
		if (ret.suiv)
		{
			ret.new = (void *)first;
//			print_ret(&ret);
			return (ret);
		}
		first = ZONE_NEXT(first);
	}
	return (ret);
}

/*
**	Return t_ret : suiv, new, prev
**		si new = NULL -> pas de maillon libre a cote
**		si suiv -> maillon apres dispo
**		si prev -> maillon avant dispo
*/

t_ret		*ft_search_maillon_prev_next(t_ret *ret, t_header *ptr, size_t size)
{
	t_zone		*zone;
	t_ret		tmp;

	if (!ret->new || !ptr)
		return (NULL);
	zone = ret->new;
	ft_init_struct_ret(ret, NULL);
	if ((char *)HEADER_MAILLON_NEXT(ptr) < (char *)ZONE_MAILLON_NEXT(zone)
			&& HEADER_MAILLON_NEXT(ptr) != HEADER_NEXT(ptr)
			&& (HEADER_MAILLON_NEXT(ptr))->len >= (size + sizeof(t_header)))
	{
		ret->suiv = HEADER_MAILLON_NEXT(ptr);
		ret->new = ptr;
		return (ret);
	}
	tmp = ft_search_maillon_header(zone->free, ptr, 0, ft_maillon_prev_suite);
	if (tmp.suiv && HEADER(tmp.suiv)->len >= (size + sizeof(t_header)))
	{
		ret->prev = tmp.suiv;
		ret->new = ptr;
	}
	return (ret);
}

/*
**	extraction des maillon concernes + recollage maillon + insertion new maillon
**		+ insertion reste free
*/

void		*ft_realloc_collage(t_zone *zone, t_ret *ret, size_t size)
{
	t_header	*a;
	t_header	*b;
	size_t		total;

	a = (ret->prev) ? ft_extract_maillon_header(&(zone->free),
			ret->prev, ft_same_adr) : ret->new;
	b = (ret->suiv) ? ft_extract_maillon_header(&(zone->free), ret->suiv,
ft_same_adr) : ft_extract_maillon_header(&(zone->taken), ret->new, ft_same_adr);
	total = a->len + b->len + 16;
	a->len = HEADER(ret->new)->len + size;
	if (ret->prev)
	{
		a = ((t_header *)ft_memmove((void *)((t_header *)(a + 1)),
				(const void *)((t_header *)(b + 1)), (a->len - size))) - 1;
		ft_link_maillon_header(&(zone->taken), a, ft_tri_adr);
	}
	b = HEADER_MAILLON_NEXT(a);
	b->len = total - a->len - 16;
	ft_link_maillon_header(&(zone->free), b, ft_tri_len);
//	print_header(a, "a");
//	print_header(b, "b");
	print_header(a, "retour realloc collage");
	return (a + 1);
}
