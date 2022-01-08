/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:38:26 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 13:42:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*casted_haystack;

	i = 0;
	casted_haystack = (char *)haystack;
	if (ft_strlen(needle) == 0)
	{
		return (casted_haystack);
	}
	while ((casted_haystack[i] != '\0') && i + ft_strlen(needle) <= len)
	{
		if (ft_strncmp(&casted_haystack[i], needle, ft_strlen(needle)) == 0)
		{
			return (&casted_haystack[i]);
		}
		i++;
	}
	return (NULL);
}
