/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:25:00 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 00:30:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			ft_hlst_add_end(t_header **first, t_header *add)
{
	t_header	*tmp;

	if (!first || !add)
	{
		ft_error_list("Problem ft_hlst_add_end\n");
		return (FALSE);
	}
	add->next = NULL;
	if (!(*first))
		*first = add;
	else
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;	
		tmp->next = add;
	}
	return (TRUE);
}


t_header	*ft_hlst_extract_size(t_header **first, size_t size, int (*condition)(void *s, size_t size))
{
	t_header	*tmp;
	t_header	*ret;

	if (!first || !(*first))
		return (ft_error_list("Problem ft_hlst_extract_size"));
	tmp = *first;
	if (condition(tmp, size))
	{
		*first = NULL;
		return (tmp);
	}
	while (tmp->next)
	{
		if (condition(tmp->next, size))
		{
			ret = tmp->next;
			tmp->next = tmp->next->next;
			return (ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
