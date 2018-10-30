/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 02:39:46 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 21:54:58 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"



void	ft_free_ts(t_zone **zone, t_header *sup)
{
	t_zone	*tmp_zone;
	t_header	*tmp_header;

	if (!sup || !zone || !(*zone))
	{
		ft_putstr("error ft_free_ts\n");
		return ;
	}
	tmp_zone = *zone;
	tmp_header = NULL;
	while (tmp_zone)
	{
		tmp_header = ft_hlst_extract_adr(&(tmp_zone->taken), sup);
		if (tmp_header)
			break ;
		tmp_zone = tmp_zone->next_zone;
	}
	if (tmp_zone)
		if (!ft_hlst_add_free(&(tmp_zone->free), tmp_header))
			ft_putstr("Error add free dans list\n");
}


void	ft_free_large(t_header **first, t_header *sup)
{
	t_header	*tmp_header;

	if (!first || !(*first) || !sup)
	{
		ft_putstr("error ft_free_large\n");
		return ;
	}
	tmp_header = ft_hlst_extract_adr(first, sup);
}

void	ft_free(void *ptr)
{
	t_header	*tmp;
	t_env		*e;

	if (!ptr)
		return ;
	if (!ft_verif_adr_ptr(ptr))
	{
		ft_error_adr("Problem adr ptr\n");
		return ;
	}
	tmp = (t_header *)((char *)ptr) - ft_align_16(sizeof(t_header));
	e = env();
	if (tmp->len <= SMALL)
		ft_free_ts((tmp->len <= TINY) ? &(e->tiny) : &(e->small), tmp);
	else
		ft_free_large(&(e->large), tmp);
}
