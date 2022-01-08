/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:04:49 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/07/16 19:53:57 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcount(char const *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	if (s[index] != c && s[index] != '\0')
	{
		count++;
	}
	while (s[index] != '\0')
	{
		if (s[index] == '\0')
		{
			break ;
		}
		if (s[index] != c && s[index - 1] == c && index != 0)
		{
			count++;
		}
		index++;
	}
	return (count);
}

static size_t	ft_strsize(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] != c && s[size] != '\0')
	{
		size++;
	}
	return (size);
}

static char	**ft_freeall(char **array, size_t n)
{
	size_t	index;

	index = 0;
	while (index <= n)
	{
		free(array[n]);
		index++;
	}
	free(array);
	return (NULL);
}

static void	*ft_fill_array(char ***array, char const *s, char c, size_t count)
{
	size_t	strsize;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] != '\0' && n < count)
	{
		if (s[i] != c && s[i] != '\0')
		{
			strsize = ft_strsize(&s[i], c);
			(*array)[n] = ft_substr(s, i, strsize);
			if ((*array)[n] == NULL)
			{
				ft_freeall(*array, n);
				return (NULL);
			}
			i += strsize;
			n++;
		}
		i++;
	}
	(*array)[n] = NULL;
	return (*array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	strcount;

	if (s == NULL)
		return (NULL);
	strcount = ft_strcount(s, c);
	array = malloc((strcount + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (ft_fill_array(&array, s, c, strcount) == NULL)
		return (NULL);
	return (array);
}
