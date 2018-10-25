/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:34:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 05:28:45 by lgiacalo         ###   ########.fr       */
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

/*

int		ft_tri_adr(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (ft_error_condition("Probleme : Tri_adr\n"));
	if (s1 <= s2)
		return (1);
	return (0);
}

int		ft_tri_len(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (ft_error_condition("Probleme : tri_len\n"));
	if (((t_header *)s1)->len <= ((t_header *)s2)->len)
		return (1);
	return (0);
}

int		ft_same_adr(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (ft_error_condition("Probleme : Same_adr\n"));
	if (s1 == s2)
		return (1);
	return (0);
}

int		ft_maillon_prev_suite(void *s1, void *s2)
{
	if (!s1 || !s2)
		return (ft_error_condition("Probleme : maillon_prev_suite\n"));
	if (s1 == s2)
		return (0);
	if (HEADER_MAILLON_NEXT(s2) == HEADER(s1))
		return (1);
	return (0);
}
*/
