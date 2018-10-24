/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:34:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 19:11:17 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		ft_tri_adr(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (s1 <= s2)
		return (1);
	return (0);
}

int		ft_tri_len(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (-1);
//	print_header((t_header *)s2, "in tri_len");
	write(1, "merde\n", 6);
	if (((t_header *)s1)->len <= ((t_header *)s2)->len)
		return (1);
	return (0);
}

int		ft_tri_len_more_header(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (-1);
	if ((((t_header *)s1)->len + sizeof(t_header)) <= ((t_header *)s2)->len)
		return (1);
	return (0);
}

int		ft_same_adr(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (s1 == s2)
		return (1);
	return (0);
}

int		ft_maillon_prev_suite(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (s1 == s2)
		return (0);
	if (HEADER_MAILLON_NEXT(s2) == HEADER(s1))
		return (1);
	return (0);
}
