/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:25:00 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 05:11:34 by lgiacalo         ###   ########.fr       */
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


int		ft_hlst_add_malloc(t_header **first, t_header *add)
{
	t_header	*prev;
	t_header	*suiv;

	if (!first || !add)
	{
		ft_error_list("Problem ft_lst_add_malloc");
		return (FALSE);
	}
	add->next = NULL;
	if (!(*first))
		*first = add;
	else
	{
		prev = *first;
		suiv = (*first)->next;
		while (suiv)
		{
			if (add < suiv)
				break ;
			prev = suiv;
			suiv = suiv->next;
		}
		if (suiv)
		{
			prev->next = add;
			add->next = suiv;
		}
		else
		{
			if (prev < add)
				prev->next = add;
			else
			{
				*first = add;
				add->next = prev;
			}
		}
	}
	return (TRUE);
}

int		ft_hlst_add_free(t_header **first, t_header *add)
{
	t_header	*prev;
	t_header	*suiv;

	if (!first || !add)
	{
		ft_error_list("Problem ft_lst_add_malloc");
		return (FALSE);
	}
	add->next = NULL;
	if (!(*first))
		*first = add;
	else
	{
		prev = *first;
		suiv = (*first)->next;
		while (suiv)
		{
			if (add->len < suiv->len)
				break ;
			prev = suiv;
			suiv = suiv->next;
		}
		if (suiv)
		{
			prev->next = add;
			add->next = suiv;
		}
		else
		{
			if (prev->len < add->len)
				prev->next = add;
			else
			{
				*first = add;
				add->next = prev;
			}
		}
	}
	return (TRUE);
}

t_header	*ft_hlst_extract_size(t_header **first, size_t size, int (*condition)(void *s, size_t size))
{
	t_header	*tmp;
	t_header	*ret;

	if (!first || !(*first))
		return (ft_error_list("Problem ft_hlst_extract_size\n"));
	tmp = *first;
	if (condition(tmp, size))
	{
		*first = tmp->next;;
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

t_header	*ft_hlst_extract_adr(t_header **first, t_header *sup)
{
	t_header	*tmp;

	if (!first || !(*first) || !sup)
		return (ft_error_list("Probleme ft_hlst_extract_adr\n"));
	tmp = *first;
	if (tmp == sup)
	{
		*first = tmp->next;
		return (tmp);
	}
	while (tmp->next)
	{
		if (tmp->next == sup)
		{
			tmp->next = sup->next;
			return (sup);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
