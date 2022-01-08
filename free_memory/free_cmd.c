/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:05:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 20:18:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_cmd_array(t_cmd **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		free(command[i]);
		command[i] = NULL;
		i++;
	}
	free(command);
	command = NULL;
}

void	free_cmd_content(t_cmd **command, int cmd_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < cmd_count)
	{
		j = 0;
		while (command[i]->content[j] != NULL)
		{
			free(command[i]->content[j]);
			command[i]->content[j] = NULL;
			j++;
		}
		free(command[i]->content);
		command[i]->content = NULL;
		i++;
	}
}

void	free_cmd_with_path(t_cmd **command, int	count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (command[i]->with_path != NULL)
		{
			free(command[i]->with_path);
			command[i]->with_path = NULL;
		}
		i++;
	}
}
