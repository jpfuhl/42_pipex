/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:05:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/15 20:10:27 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	len;
	size_t	index;

	if (s == NULL)
	{
		return (NULL);
	}
	index = 0;
	len = ft_strlen(s);
	array = malloc((len + 1) * sizeof(char));
	if (array == NULL)
	{
		return (NULL);
	}
	while (index < len)
	{
		array[index] = f(index, s[index]);
		index++;
	}
	array[index] = '\0';
	return (array);
}
