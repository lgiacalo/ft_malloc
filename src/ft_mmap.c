/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:12:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 20:45:43 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** MAP_FAILED == (void *)-1
*/

static void		ft_init_zone(t_zone *zone, size_t size)
{
	if (!zone)
		return ;
	zone->len_zone = size;
	zone->taken = NULL;
	zone->free = (t_header *)((char *)zone + ft_align(sizeof(t_zone), 16));
	zone->free->len = size - ft_align(sizeof(t_zone), 16) - ft_align(sizeof(t_header), 16);
	zone->next_zone = NULL;
}

static void		ft_init_header(t_header *header, size_t size)
{
	if (!header)
		return ;
	header->len = size - ft_align(sizeof(t_header), 16);
	header->next = NULL;
}

t_zone			*ft_mmap_zone(size_t size)
{
	t_zone	*zone;
	t_env	*e;

	size = ft_align((size + sizeof(t_zone)), getpagesize());
	zone = (t_zone *)ft_mmap(size);
	if (!zone)
		return (NULL);
	e = env();
	ft_init_zone(zone, size);
	ft_zlst_add_end(((int)size == TINY_ZONE)
			? &(e->tiny) : &(e->small), zone);
	return (zone);
}

t_header		*ft_mmap_header(size_t size)
{
	t_header	*header;
	t_env		*e;

	size = ft_align((size + sizeof(t_header)), getpagesize());
	header = (t_header *)ft_mmap(size);
	if (!header)
		return (NULL);
	ft_init_header(header, size);
	e = env();
	ft_hlst_add_end(&(e->large), header);
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
