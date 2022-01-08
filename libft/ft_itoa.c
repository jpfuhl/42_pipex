/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:44:29 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/20 13:52:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr_itoa(int n, size_t count, size_t i, char *str)
{	
	if ((n >= 0) && (i + 1 == count))
		str[i + 1] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		str[i + 1] = '\0';
	}
	if (n > 9)
	{
		ft_putnbr_itoa(n % 10, count, i--, str);
		ft_putnbr_itoa(n / 10, count, i--, str);
	}
	if (0 <= n && n <= 9)
	{
		str[i] = n + 48;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*array;

	if (n == -2147483648)
		array = ft_strdup("-2147483648");
	else
	{
		i = ft_countdigits(n) + 1;
		if (n < 0)
			i += 1;
		array = malloc(i * sizeof(char));
		if (array == NULL)
			return (NULL);
		array = ft_putnbr_itoa(n, (i - 1), (i - 2), array);
	}
	return (array);
}
