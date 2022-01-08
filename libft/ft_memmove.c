/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:47:28 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 16:44:43 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (len == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dest < src)
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
		return (dest);
	}
	while (len > 0)
	{
		((char *)dest)[len - 1] = ((char *)src)[len - 1];
		len--;
	}
	return (dest);
}
