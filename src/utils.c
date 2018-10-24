/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:28:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 23:24:00 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src <= dst)
	{
		while (i < len)
		{
			i++;
			*(unsigned char*)(dst + len - i) =
			*(unsigned char*)(src + len - i);
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

int		ft_putstr(char const *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_aputnbr(long long int n)
{
	unsigned long long int	nbr;

	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	else
		nbr = n;
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	if (nbr >= 10)
	{
		ft_aputnbr(nbr / 10);
		ft_aputnbr(nbr % 10);
	}
	return ;
}
