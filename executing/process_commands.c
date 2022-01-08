/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:58:54 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 20:42:11 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute_command(t_cmd *command, char **envp)
{
	int	len;

	if (command->with_path == NULL)
	{
		write(2, "zsh: command not found: ", 25);
		len = ft_strlen(command->content[0]);
		write(2, &(*command->content[0]), len);
		write(2, "\n", 1);
		exit(EXIT_COMMAND_NOT_ACCESSIBLE);
	}
	if (execve(command->with_path, command->content, envp) == -1)
	{
		exit (EXIT_COMMAND_NOT_EXECUTABLE);
	}
}

void	pipex(t_vars *vars, t_cmd *command)
{
	if (dup2(*command->fd_in, STDIN_FILENO) == -1)
		exit (EXIT_REDIRECTING_STDIN_FAILURE);
	if (dup2(*command->fd_out, STDOUT_FILENO) == -1)
		exit (EXIT_REDIRECTING_STDOUT_FAILURE);
	close(vars->pipex[0]);
	close(vars->pipex[1]);
	close(vars->fd_infile);
	close(vars->fd_outfile);
}

void	launch_exec_process(t_vars *vars, int i)
{
	pid_t	grandchild;

	grandchild = fork();
	if (grandchild == -1)
	{
		exit (EXIT_FORKING_PROCESS_FAILURE);
	}
	if (grandchild == 0)
	{
		pipex(vars, vars->command[i]);
		execute_command(vars->command[i], vars->envp);
	}
	else
	{
		wait (NULL);
		pipex(vars, vars->command[i + 1]);
		execute_command(vars->command[i + 1], vars->envp);
	}
}

void	process_commands(t_vars *vars)
{
	pid_t	child;
	int		i;

	i = 0;
	child = fork();
	if (child == -1)
	{
		exit (EXIT_FORKING_PROCESS_FAILURE);
	}
	if (child == 0)
	{
		launch_exec_process(vars, i);
	}
	else
	{
		close(vars->pipex[0]);
		close(vars->pipex[1]);
		close(vars->fd_infile);
		close(vars->fd_outfile);
	}
}
