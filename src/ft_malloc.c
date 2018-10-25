/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:41:06 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 05:13:11 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** size en octet !!
*/

static t_header	*ft_malloc_boucle_zone(t_zone *zone, size_t size)
{
	t_zone		*place;
	t_zone		*tmp;
	t_header	*ret;

	place = zone;
	ret = NULL;
	while (place)
	{
		if ((ret = ft_malloc_boucle_header(place, size)) != NULL)
			break ;
		tmp = place;
		place = place->next_zone;
	}
	return (ret);
}

/*
** Return False - prevoir erreur de mmap en fonction de variable d'env
*/

static void		*ft_malloc_ts(t_zone **zone, size_t len_zone, size_t size)
{
	t_zone		*z;
	t_header	*place;

	place = NULL;
	z = NULL;
	if (*zone && (*zone)->free)
		place = ft_malloc_boucle_zone(*zone, size);
	if (!place)
	{
		if (!(z = ft_mmap_zone(len_zone)))
			return (ft_error_mmap(""));
		place = ft_malloc_boucle_header(z, size);
	}
	return ((place) ? (place + 1) : NULL);
}

static void		*ft_malloc_large(size_t size)
{
	t_header	*header;

	if (!(header = ft_mmap_header(size)))
		return (ft_error_mmap(""));
	return (header + 1);
}

void			*ft_malloc(size_t size)
{
	t_env	*e;

	e = env();
	if (size <= 0)
		return (NULL);
	size = ft_align_16(size);
	if (size <= SMALL_MAX_ALLOC)
		return (ft_malloc_ts(
			(size <= TINY_MAX_ALLOC) ? &(e->tiny) : &(e->small), 
			(size <= TINY_MAX_ALLOC) ? TINY_ZONE : SMALL_ZONE, size));
	else
		return (ft_malloc_large(size));
}
