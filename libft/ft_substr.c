/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:19:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/15 20:44:37 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slength;

	if (s == NULL)
	{
		return (NULL);
	}
	i = 0;
	slength = ft_strlen(s);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
	{
		return (NULL);
	}
	while (s[start] != '\0' && i < len && start < slength)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
