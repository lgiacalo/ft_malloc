/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 02:39:46 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 04:05:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"



void	ft_free_ts(t_zone **zone, t_header *sup)
{
	t_zone	*tmp_zone;
	t_header	*tmp_header;

	if (!sup || !zone || !(*zone))
		ft_putstr("error ft_free_ts\n");
	tmp_zone = *zone;
	tmp_header = NULL;
	while (tmp_zone)
	{
		tmp_header = ft_hlst_extract_adr(&(tmp_zone->taken), sup);
		if (tmp_header)
			break ;
		tmp_zone = tmp_zone->next_zone;
	}
	print_header(tmp_header, "free extrait de taken");
}


void	ft_free_large(t_header *sup)
{
	print_header(sup, "free large");
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
	tmp = ((t_header *)ptr) - 1;
	print_header(tmp, "maillon ok");
	e = env();
	if (tmp->len <= SMALL_MAX_ALLOC)
		ft_free_ts((tmp->len <= TINY_MAX_ALLOC) ? &(e->tiny) : &(e->small), tmp);
	else
		ft_free_large(tmp);
}
