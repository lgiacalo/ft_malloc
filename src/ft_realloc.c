/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 04:55:39 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/30 20:49:17 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	t_header	*ret;
	t_header	*tmp;

	if (!ptr)
		return (NULL);
	if (!ft_verif_adr_ptr(ptr))
		return (ptr);
	tmp = (t_header *)((char *)ptr - ft_align(sizeof(t_header), 16));
	if (size <= tmp->len)
		return (ptr);

	ret = ft_malloc(size);
	ret = ft_memmove(ret, ptr, tmp->len);
	ft_free(ptr);	
	return (ret);
}
