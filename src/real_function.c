/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 05:13:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 05:16:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void					*malloc(size_t size)
{
	return (ft_malloc(size));
}

void					free(void *ptr)
{
	return (ft_free(ptr));
}

void					*realloc(void *ptr, size_t size)
{
	return (ft_realloc(ptr, size));
}
