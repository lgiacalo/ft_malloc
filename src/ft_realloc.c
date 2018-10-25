/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 04:55:39 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 06:45:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	t_header	*ret;
	t_header	*tmp;

	ft_putstr("\nREALLOC\n");
	if (!ptr)
		return (ft_malloc(size));
	if (!ft_verif_adr_ptr(ptr))
		return (ptr);
	if (ptr && size == 0)
	{
		ft_free(ptr);
		return (ft_malloc(16));
	}
	tmp = (t_header *)ptr - 1;
	if (size <= tmp->len)
		return (ptr);

	ret = ft_malloc(size);
	ret = ft_memmove(ret, ptr, tmp->len);
	ft_free(ptr);	
	return (ret);
}
