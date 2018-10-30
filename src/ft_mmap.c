/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:12:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 22:09:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** MAP_FAILED == (void *)-1
*/

static int		ft_choice_max_alloc(size_t size)
{
	if (size <= TINY)
		return (TINY);
	if (size <= SMALL)
		return  (SMALL);
	return (0);
}

static void		ft_init_zone(t_zone *zone, size_t size)
{
	if (!zone)
		return ;
	zone->len_zone = size;
	zone->taken = NULL;
	zone->free = (t_header *)((char *)zone + ft_align_16(sizeof(t_zone)));
	zone->free->len = size - ft_align_16(sizeof(t_zone) - ft_align_16(sizeof(t_header)));
	zone->free->next = NULL;
	zone->next_zone = NULL;
}

static void		ft_init_header(t_header *header, size_t size)
{
	if (!header)
		return ;
	header->len = size - ft_align_16(sizeof(t_header));
	header->next = NULL;
}

t_zone			*ft_mmap_zone(size_t size)
{
	t_zone	*zone;
	size_t	max_alloc;
	size_t	alloc;

	max_alloc = ft_choice_max_alloc(size);
	alloc = ft_align_page(((size + ft_align_16(sizeof(t_header))) * 100) + ft_align_16(sizeof(t_zone)));
	zone = (t_zone *)ft_mmap(alloc);
	if (!zone)
		return (NULL);
	ft_init_zone(zone, alloc);
	ft_zlst_add_end((max_alloc == TINY)
			? &((env())->tiny) : &((env())->small), zone);
	return (zone);
}

t_header		*ft_mmap_header(size_t size)
{
	t_header	*header;
	size_t		alloc;

	alloc = ft_align_page(ft_align_16(sizeof(t_header)) + ft_align_16(size));
	header = (t_header *)ft_mmap(alloc);
	if (!header)
		return (NULL);
	ft_init_header(header, alloc);
	ft_hlst_add_end(&((env())->large), header);
	return (header);
}

void			*ft_mmap(size_t size)
{
	void	*ret;

	ret = mmap(0, size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
		return (ft_error_mmap(""));
	return (ret);
}
