/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 00:01:39 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 00:49:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_header	*ft_malloc_boucle_header(t_zone *zone, size_t size)
{
	t_header	*tmp;

	if (!zone)
		return (NULL);
	tmp = ft_hlst_extract_size(&(zone->free), size, ft_tri_size_more_header);
	if (!tmp)
		return (NULL);
		

	print_header(tmp, "retour malloc_boucle_header");
	ft_putstr("Trouve\n");
	return (tmp);
}
