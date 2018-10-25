/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:34:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 06:52:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		ft_tri_size_more_header(void *s, size_t size)
{
	if (!s || !size)
		return (ft_error_condition("Probleme : Tri_len_more_header\n"));
	if ((((t_header *)s)->len + sizeof(t_header)) >= size)
		return (1);
	return (0);
}
