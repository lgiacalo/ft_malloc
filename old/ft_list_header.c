/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:16:53 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 19:20:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_fusion(t_header **first, t_header *s1, t_header *s2)
{
	ft_extract_maillon_header(first, s2, ft_same_adr);
	s1->len = s1->len + sizeof(t_header) + s2->len;
	s2->next = NULL;
	ft_extract_maillon_header(first, s1, ft_same_adr);
	ft_link_maillon_header(first, s1, ft_tri_len);
	ft_fusion_maillon_header(first, s1);
}

void		ft_fusion_maillon_header(t_header **first, t_header *s)
{
	t_header *tmp;

	if (!first || !(*first) || !((*first)->next) || !s)
		return ;
	tmp = *first;
	while (tmp)
	{
		if ((t_header *)(((char *)(s + 1)) + s->len) == tmp)
			return (ft_fusion(first, s, tmp));
		if ((t_header *)(((char *)(tmp + 1)) + tmp->len) == s)
			return (ft_fusion(first, tmp, s));
		tmp = tmp->next;
	}
	return ;
}

/*
**	Accrochage new maillon selon fonction  int *condition(void *, void *)
**		Return void;
**	// PENSER A FUSIONNER LES MAILLONS FREE
*/

void		ft_link_maillon_header(t_header **first, t_header *new,
									int (*condition)(void *, void *))
{
	t_ret		ret;


	if (!new || !first)
		return ;
	if (!(*first))
		*first = new;
	else
	{
		ret = ft_search_maillon_header(*first, new, 1, condition);
		write(1, "MALLOC22\n", 9);
		if (ret.suiv == ret.prev)
			*first = new;
		else
			HEADER_NEXT(ret.prev) = HEADER(ret.new);
		HEADER_NEXT(ret.new) = HEADER(ret.suiv);
	}
}

/*
**	Extrait un maillon en raccrochant correctement les autres
*/

t_header	*ft_extract_maillon_header(t_header **first, t_header *s,
									int (*condition)(void *, void*))
{
	t_ret	ret;
	write(1, "MALLOC5\n", 8);

	if (!first || !(*first))
		return (NULL);
	ret = ft_search_maillon_header(*(first), s, 0, condition);
	if ((*first) == ret.suiv)
		*first = HEADER_NEXT(ret.suiv);
	else if (ret.suiv)
	{

	write(1, "MALLOC0\n", 8);
		HEADER_NEXT(ret.prev) = HEADER_NEXT(ret.suiv);
		HEADER_NEXT(ret.suiv) = NULL;
	}
	return (ret.suiv);
}

/*
**	Search maillon selon fonction int *condition(void *, void *)
**		Return strut t_ret : prev, new et suiv
*/

t_ret		ft_search_maillon_header(t_header *first, t_header *new, int add,
		int (*condition)(void *, void *))
{
	t_ret		ret;

	write(1, "MALLOC6\n", 8);
	ft_init_struct_ret(&ret, (add) ? new : NULL);
	if (!new || !first)
		return (ret);
	ret.prev = (void *)first;
	ret.suiv = (void *)first;
//	show_alloc_mem();
//	print_list_header(first, "list free");
	write(1, "MALLOC6a\n", 9);
	while (ret.suiv)
	{

		write(1, "MALLOC7\n", 8);
//		print_header((t_header *)ret.prev, "prev ");
		if (condition && (*condition)(new, ret.suiv))
			break ;
		ret.prev = ret.suiv;
		ret.suiv = HEADER_NEXT(ret.suiv);
	}

	write(1, "MALLOC8\n", 8);
	return (ret);
}
