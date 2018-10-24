/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 23:27:54 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 23:17:45 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		ft_chrstr_ind(char c, char *str)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (i);
		i++;
	}
	i++;
	return (-i);
}

int		ft_strstrchr_ind(char *s1, char *s2)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0')
	{
		ret = ft_chrstr_ind(s1[i], s2);
		if (ret >= 0)
			return (i);
		i++;
	}
	i++;
	return (-i);
}

int		ft_verif_base(char *base)
{
	int	i;

	i = 0;
	if (!base || (ft_strlen(base) < 2))
		return (0);
	while (base[i] != '\0' && base[i + 1] != '\0')
	{
		if ((ft_chrstr_ind(base[i], (base + i + 1))) >= 0)
			return (0);
		i++;
	}
	if ((ft_strstrchr_ind("+-", base)) >= 0)
		return (0);
	return (1);
}

void	ft_putnbr_base(int n, char *base)
{
	long int	nbr;
	int			nbr_base;

	nbr = n;
	if ((ft_verif_base(base)) == 0)
		return ;
	nbr_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr < nbr_base)
		ft_putchar(base[nbr]);
	if (nbr >= nbr_base)
	{
		ft_putnbr_base((nbr / nbr_base), base);
		ft_putnbr_base((nbr % nbr_base), base);
	}
}

void	ft_putpnbr_base(unsigned long long int n, char *base)
{
	unsigned long long int	nbr;
	unsigned int			nbr_base;

	nbr = n;
	if ((ft_verif_base(base)) == 0)
		return ;
	nbr_base = (unsigned int)ft_strlen(base);
	(nbr < nbr_base) ? ft_putchar(base[nbr]) : 0;
	if (nbr >= nbr_base)
	{
		ft_putnbr_base((nbr / nbr_base), base);
		ft_putnbr_base((nbr % nbr_base), base);
	}
}
