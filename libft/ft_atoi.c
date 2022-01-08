/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:20:27 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 16:29:24 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_skip(const char *str)
{
	size_t	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') && (str[i + 1] != '-'))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long int	nbr;
	int			neg;

	nbr = 0;
	neg = 1;
	i = ft_skip(str);
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (nbr <= 2147483647)
			nbr = nbr * 10 + (str[i] - 48);
		else
			break ;
		i++;
	}
	if (nbr * neg < -2147483648)
		return (0);
	if (nbr * neg > 2147483647)
		return (-1);
	return (nbr * neg);
}
