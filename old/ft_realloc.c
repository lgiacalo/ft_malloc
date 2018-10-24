/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 21:24:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 19:31:48 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Attention ne pas depasser le max !
*/

static t_zone	*ft_search_zone_with_adr(t_zone *first, t_header *ptr)
{
	if (!first || !ptr)
		return (NULL);
	while (first)
	{
		if (((void *)first <= (void *)ptr)
			&& ((void *)ptr < (void *)ZONE_MAILLON_NEXT(first)))
			return (first);
		first = ZONE_NEXT(first);
	}
	return (NULL);
}

/*
**	Realloc dans une zone plus grande
**		tiny -> small
**		small -> large
*/

static void	*ft_zone_more(t_zone **before, t_header *ptr, size_t size)
{
	t_header	*header_tmp;
	t_header	*ret;
	t_zone		*zone_tmp;
	int			total;

	write(1, "REALLOC MORE\n", 13);
	zone_tmp = NULL;
	ret = NULL;
	if (!(zone_tmp = ft_search_zone_with_adr(*before, ptr)))
		return (NULL);
	if (!(header_tmp = ft_extract_maillon_header(&(zone_tmp->taken),
					ptr, ft_same_adr)))
		return (NULL);
	total = header_tmp->len + size;
//	ft_fusion_maillon_header(&(zone_tmp->free), header_tmp);
	if (!(ret = (t_header *)malloc(size)))
		return (NULL);
	ret = ((t_header *)ft_memmove((void *)ret,
			(const void *)((t_header *)(header_tmp + 1)), (total - size < size) ? (total - size) : (size) )) - 1;
	if (ft_zone_is_empty(zone_tmp))
		if ((zone_tmp = ft_extract_maillon_zone(before, zone_tmp)))
			ft_munmap(zone_tmp, zone_tmp->len_zone);
//	print_header(ret, "zone more");
	return (ret + 1);
}

/*
**	Realloc dans la meme zone
*/

static void	*ft_same_zone(t_zone **zone, t_header *ptr, size_t size)
{
	t_zone		*zone_tmp;
	t_ret		ret;
	t_ret		*tmp;

	write(1, "REALLOC SAME\n", 13);
//	print_header(ptr, "Ptr realloc : SAME ZONE");
	ret = ft_search_header_zone(*zone, ptr);
	if (!ret.suiv)
		return (NULL);
	zone_tmp = (t_zone *)ret.new;
	tmp = ft_search_maillon_prev_next(&ret, ptr, size);
	if (!(tmp->new))
		return (ft_zone_more(zone, ptr, size));
	else
		return (ft_realloc_collage(zone_tmp, tmp, size));
}

static void	*ft_realloc_large(t_header **first, t_header *ptr, size_t size)
{
	t_header	*tmp;
	t_header	*ret;

	write(1, "REALLOC LARGE\n", 14);
	tmp = NULL;
	tmp = (ft_search_maillon_header(*first, ptr, 0, ft_same_adr)).suiv;
	if (!tmp)
		return (NULL);
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ret = ((t_header *)ft_memmove((void *)ret,
			(const void *)((t_header *)(ptr + 1)), (ptr->len)) - 1);
	free(ptr + 1);
//	print_header(ret, "realloc large");
	return (ret + 1);
}

void		*realloc(void *ptr, size_t size)
{
	t_header	*tmp;
	t_env		*e;

//	show_alloc_mem();
	write(1, "REALLOC\n", 8);
	e = env();
//	print_env(e);
	if (!ptr || !size)
	{
		write(1, "NULLLL\n", 7);
		return (malloc(size ? size : 16));
	}
	if (ft_verif_adr_ptr(ptr))
	{
	write(1, "REALLOC - IF\n", 13);
	tmp = ((t_header *)ptr) - 1;
	printf("size de base = %zu et realloc = %zu\n", tmp->len, size);
	if (tmp->len <= TINY_MAX_ALLOC)
		return (((size) <= TINY_MAX_ALLOC)
				? ft_same_zone(&(e->tiny), tmp, size)
				: ft_zone_more(&(e->tiny), tmp, size));
	else if (tmp->len <= SMALL_MAX_ALLOC)
		return (((size) <= SMALL_MAX_ALLOC)
				? ft_same_zone(&(e->small), tmp, size)
				: ft_zone_more(&(e->small), tmp, size));
	else
		return (ft_realloc_large(&(e->large), tmp, size));
}
	return (NULL); // renvoyer ptr si non null
}
