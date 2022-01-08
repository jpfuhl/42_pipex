/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:08:32 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/12 17:16:19 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	while (j > 0 && ft_strchr(set, s1[j - 1]) != NULL)
	{
		j--;
	}
	if (i >= j)
	{
		return (ft_strdup(""));
	}
	trim = ft_substr(s1, i, j - i);
	return (trim);
}
