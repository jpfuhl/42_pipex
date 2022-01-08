/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_streams.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:24:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 04:42:45 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	redirect_cmd(t_vars *vars, t_cmd *command)
{
	command->fd_in = &vars->pipex[0];
	command->fd_out = &vars->pipex[1];
}

void	redirect_outfile(t_vars *vars, t_cmd *command)
{
	command->fd_in = &vars->pipex[0];
	command->fd_out = &vars->fd_outfile;
}

void	redirect_infile(t_vars *vars, t_cmd *command)
{
	command->fd_in = &vars->fd_infile;
	command->fd_out = &vars->pipex[1];
}

void	redirect_streams(t_vars *vars, t_cmd **command, int cmd_count)
{
	int	i;

	if (pipe(vars->pipex) == -1)
	{
		exit (EXIT_CREATING_PIPE_FAILURE);
	}
	i = 0;
	while (i < cmd_count)
	{
		if (i == 0)
		{
			redirect_infile(vars, command[i]);
		}
		else if (i == cmd_count - 1)
		{
			redirect_outfile(vars, command[i]);
		}
		else
		{
			redirect_cmd(vars, command[i]);
		}
		i++;
	}
}
