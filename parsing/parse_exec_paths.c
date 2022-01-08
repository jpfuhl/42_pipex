/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:11:06 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/12/16 20:34:17 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_match(t_vars *vars, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (vars->exec_path[i] != NULL)
	{
		path = ft_strjoin(vars->exec_path[i], cmd);
		if (!path)
		{
			exit(EXIT_MEMORY_ALLOCATION_FAILURE);
		}
		if (access(path, F_OK | X_OK) == -1)
		{
			free(path);
			path = NULL;
			i++;
			continue ;
		}
		else
			break ;
	}
	return (path);
}

void	set_command_path(t_vars *vars, t_cmd **command)
{
	int	i;

	i = 0;
	while (i < vars->cmd_count)
	{
		if (command[i]->includes_path == 0)
		{
			command[i]->with_path = find_match(vars, command[i]->content[0]);
		}
		i++;
	}
}

char	*append_slash(char *path)
{
	int		i;
	int		len;
	char	*join;

	len = ft_strlen(path) + 1;
	join = malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (path[i] != '\0')
	{
		join[i] = path[i];
		i++;
	}
	join[i] = '/';
	join[i + 1] = '\0';
	free(path);
	return (join);
}

char	*find_line_with_paths(char **envp)
{
	char	*line;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		line = ft_strnstr(envp[i], "PATH=", 5);
		if (line)
			break ;
		i++;
	}
	return (line);
}

void	parse_exec_paths(t_vars *vars, char **envp)
{
	char	*line;
	int		i;

	line = find_line_with_paths(envp);
	vars->exec_path = ft_split(line + 5, ':');
	if (!vars->exec_path)
		exit (EXIT_MEMORY_ALLOCATION_FAILURE);
	i = 0;
	vars->path_count = 0;
	while (vars->exec_path[i] != NULL)
	{
		vars->path_count += 1;
		vars->exec_path[i] = append_slash(vars->exec_path[i]);
		if (!vars->exec_path[i])
			exit (EXIT_MEMORY_ALLOCATION_FAILURE);
		i++;
	}
	set_command_path(vars, vars->command);
}
