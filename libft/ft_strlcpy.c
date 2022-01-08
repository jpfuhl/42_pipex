/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:10:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 13:41:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	max;

	if (dst == 0 || src == 0)
		return (0);
	i = 0;
	srclen = ft_strlen(src);
	max = dstsize - 1;
	if (dstsize == 0)
		return (srclen);
	if (srclen == 0)
	{
		dst[0] = '\0';
		return (srclen);
	}
	while (i < max && i < srclen)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (srclen);
}
