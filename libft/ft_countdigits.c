/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:50:03 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/20 13:53:13 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Additional function to count digits of an integer. */

#include "libft.h"

size_t	ft_countdigits(int n)
{
	if ((n / 10) == 0)
	{
		return (1);
	}
	return (1 + ft_countdigits(n / 10));
}
