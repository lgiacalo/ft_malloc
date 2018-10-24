/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 21:40:03 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 23:16:17 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Error print en fonction de var d'environnement
*/

void	*ft_error_mmap(char *str)
{
	(void)str;
	write(1, "Error mmap()\n", 13);
	return (NULL);
}

void	*ft_error_munmap(char *str)
{
	(void)str;
	write(1, "Error munmap()\n", 15);
	return (NULL);
}

/*
void	ft_init_struct_ret(t_ret *ret, void *new)
{
	if (!ret)
		return ;
	ret->prev = NULL;
	ret->new = new;
	ret->suiv = NULL;
}
*/

