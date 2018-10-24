/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:43:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 17:34:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Si pas assez de place pour header next, octet perdu, rajouter a size
*/

static void	ft_display_size_taken(t_header *neww, size_t size)
{
	t_header *tmp;

	write(1, "MALLOC26\n", 9);
	if (((int)neww->len - ((int)size + (int)sizeof(t_header))) >= 0)
	{
		write(1, "MALLOC27a\n", 10);
		tmp = (t_header *)(((char *)(neww + 1)) + size);
		write(1, "MALLOC27b\n", 10);
		tmp->len = neww->len - (size + sizeof(t_header));
		write(1, "MALLOC27c\n", 10);
		neww->next = tmp;
		write(1, "MALLOC27d\n", 10);
		neww->len = size;
		write(1, "MALLOC27e\n", 10);
//		printf("size free : %zu\n", tmp->len);
		write(1, "MALLOC27f\n", 10);
	}
	else
	{
		neww->next = NULL;
		printf("\n\tMERDE MERDE VOIR FONCTION FT_DISPLAY_SIZE_TAKEN\n\n");
	}
	write(1, "MALLOC27\n", 9);
}

static void	ft_display_new_taken(t_zone *zone, t_header *neww, size_t size)
{
	t_header	*new_free;

	ft_display_size_taken(neww, size);
	new_free = neww->next;
	neww->next = NULL;
//	show_alloc_mem();
//	print_zone(zone);
	write(1, "MALLOC25\n", 9);
	ft_link_maillon_header(&(zone->free), new_free, ft_tri_len);

	write(1, "MALLOC9\n", 8);
	ft_link_maillon_header(&(zone->taken), neww, ft_tri_adr);
	write(1, "MALLOC10\n", 9);
}

/*
**	Verifier sil reste assez pour un autre maillon, sinon chercher suivant ?
*/

t_header	*ft_boucle_header(t_zone *place, size_t size)
{
	t_header	*tmp;
	t_header	prev;

	write(1, "MALLOC4\n", 8);
	prev.len = size;
	tmp = NULL;
	tmp = ft_extract_maillon_header(&(place->free), &prev,
										ft_tri_len_more_header);

	write(1, "MALLOC23\n", 9);
	if (!tmp)
	{
		write(1, "MALLOC24\n", 9);
		return (NULL);
	}
	ft_display_new_taken(place, tmp, size);
	return (tmp);
}
