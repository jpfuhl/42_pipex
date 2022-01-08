/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:17:53 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 13:31:01 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	len;
	size_t	max;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	len = dstlen + srclen;
	max = (dstsize - dstlen - 1);
	if (dstsize <= dstlen)
	{
		return (dstsize + srclen);
	}
	while (i < max && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (len);
}
