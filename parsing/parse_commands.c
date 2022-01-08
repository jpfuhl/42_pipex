/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:22:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 20:32:00 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fill_cmd_array(t_cmd **command, char **argv, int cmd_count)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		command[i]->content = ft_split(argv[i + 2], ' ');
		if (!command[i]->content)
			exit (EXIT_MEMORY_ALLOCATION_FAILURE);
		if (access(command[i]->content[0], F_OK | X_OK) == 0)
		{
			command[i]->with_path = ft_strdup(command[i]->content[0]);
			if (!command[i]->with_path)
				exit (EXIT_MEMORY_ALLOCATION_FAILURE);
			command[i]->includes_path = 1;
		}
		else
		{
			command[i]->with_path = NULL;
			command[i]->includes_path = 0;
		}
		i++;
	}
}

void	initialize_cmd_array(t_cmd **command, int cmd_count)
{
	int	i;

	i = 0;
	while (i < cmd_count + 1)
	{
		command[i] = NULL;
		i++;
	}
}

void	create_cmd_array(t_vars *vars, int cmd_count)
{
	int	i;

	vars->command = malloc((cmd_count + 1) * sizeof(t_cmd *));
	if (!vars->command)
	{
		exit (EXIT_MEMORY_ALLOCATION_FAILURE);
	}
	initialize_cmd_array(vars->command, cmd_count);
	i = 0;
	while (i < cmd_count)
	{
		vars->command[i] = malloc(sizeof(t_cmd));
		if (!vars->command[i])
		{
			free_cmd_array(vars->command);
			exit (EXIT_MEMORY_ALLOCATION_FAILURE);
		}
		i++;
	}
}

void	parse_commands(t_vars *vars, char **argv, int cmd_count)
{
	create_cmd_array(vars, cmd_count);
	fill_cmd_array(vars->command, argv, cmd_count);
}
