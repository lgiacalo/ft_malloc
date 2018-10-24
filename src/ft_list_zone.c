/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_zone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:54:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 00:01:00 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	ft_zlst_add_end(t_zone **first, t_zone *add)
{
	t_zone	*tmp;

	if (!first || !add)
	{
		ft_error_list("Probleme ft_hlst_add_end\n");
		return (FALSE);
	}
	add->next_zone = NULL;
	if (!(*first))
		*first = add;
	else
	{
		tmp = *first;
		while (tmp->next_zone)
		{
			tmp = tmp->next_zone;	
		}
		tmp->next_zone = add;
	}
	return (TRUE);
}
