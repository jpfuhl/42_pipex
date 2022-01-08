/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:57:52 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 13:30:43 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*array;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	array = malloc(len * sizeof(char));
	if (array == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
