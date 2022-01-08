/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:00:09 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/06 16:08:05 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;
	size_t	i;
	size_t	j;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	strjoin = malloc(len * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}
