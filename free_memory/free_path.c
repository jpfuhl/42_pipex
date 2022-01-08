/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:13:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 20:13:36 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_path_array(char **exec_path)
{
	int	i;

	i = 0;
	while (exec_path[i])
	{
		free(exec_path[i]);
		exec_path[i] = NULL;
		i++;
	}
	free(exec_path);
	exec_path = NULL;
}
