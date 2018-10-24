/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:21:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 19:20:33 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_boucle_zone_free(t_zone **first, t_header *s)
{
	t_zone		*tmp;
	t_header	*sup;

	write(1, "FREE2\n", 6);
	if (!first || !(*first) || !s)
		return ;
	tmp = *first;
	sup = NULL;
	while (tmp)
	{
		if ((sup = ft_extract_maillon_header(&(tmp->taken), s, ft_same_adr)))
			break ;
		tmp = ZONE_NEXT(tmp);
	}
	if (sup)
	{
		ft_link_maillon_header(&(tmp->free), sup, ft_tri_len);
//		ft_fusion_maillon_header(&(tmp->free), sup);
	}
	if (ft_zone_is_empty(tmp)) // si plusieurs zone
		if ((tmp = ft_extract_maillon_zone(first, tmp)))
			ft_munmap(tmp, tmp->len_zone);
	if (!sup)
		printf("Introuvable tmp : %p et len : %zu\n", s, s->len);
}

void	free(void *ptr)
{
	t_zone		**first;
	t_header	*tmp;
	t_env		*e;

	write(1, "FREE\n", 5);
	if (!ptr)
		return ;
	tmp = (t_header *)(ptr - sizeof(t_header));
//	ft_putpnbr_base((unsigned long long int)tmp, "0123456789ABCDEF");
	write(1, "\n\n", 2);
//	show_alloc_mem();	
//	show_free_mem();
	first = NULL;
	e = env();

//	print_list_header(*first, "list ft_fusion");
//	show_free_mem();
	if (ft_verif_adr_ptr(ptr))
	{
//		print_header(tmp, "ptr free");
		write(1, "FRE1\n", 5);
		if (tmp->len > SMALL_MAX_ALLOC)
		{
			write(1, "FREE-IF\n", 8);
			if ((tmp = ft_extract_maillon_header(&(e->large), tmp, ft_same_adr)))
			{
				if (ft_munmap((void *)tmp, tmp->len))
					ft_error_munmap("");
			}
			else
				printf("Introuvable tmp : %p et len : %zu\n", tmp, tmp->len);
//			show_free_mem();
		}
		else
		{
			write(1, "FREE-ELSE\n", 10);
			first = (tmp->len <= TINY_MAX_ALLOC) ? &(e->tiny) : &(e->small);
			ft_boucle_zone_free(first, tmp);
//			show_free_mem();
		}
	}
}
