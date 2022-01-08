/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 07:43:45 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/12/09 00:22:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>

# define EXIT_WRONG_INPUT 1
# define EXIT_INFILE_OPEN_ERROR 2
# define EXIT_OUTFILE_OPEN_ERROR 3
# define EXIT_MEMORY_ALLOCATION_FAILURE 4
# define EXIT_COMMAND_NOT_ACCESSIBLE 5
# define EXIT_FORKING_PROCESS_FAILURE 6
# define EXIT_COMMAND_NOT_EXECUTABLE 7
# define EXIT_CREATING_PIPE_FAILURE	8
# define EXIT_REDIRECTING_STDIN_FAILURE 9
# define EXIT_REDIRECTING_STDOUT_FAILURE 10

typedef struct s_command_element
{
	char	**content;
	char	*with_path;
	int		includes_path;
	int		*fd_in;
	int		*fd_out;
}	t_cmd;

typedef struct s_program_variables
{
	char	**envp;
	int		fd_infile;
	int		fd_outfile;
	int		pipex[2];
	t_cmd	**command;
	int		cmd_count;
	char	**exec_path;
	int		path_count;
}	t_vars;

/* open_files.c */
void	open_files(t_vars *vars, int argc, char **argv);

/* parse_command.c */
void	parse_commands(t_vars *vars, char **argv, int cmd_count);
void	create_cmd_array(t_vars *vars, int size);
void	initialize_cmd_array(t_cmd **command, int size);
void	fill_cmd_array(t_cmd **command, char **argv, int cmd_count);

/* parse_exec_paths.c */
void	parse_exec_paths(t_vars *vars, char **envp);
char	*find_line_with_paths(char **envp);
char	*append_slash(char *path);
void	set_command_path(t_vars *vars, t_cmd **command);
char	*find_match(t_vars *vars, char *cmd);

/* redirect_streams.c */
void	redirect_streams(t_vars *vars, t_cmd **command, int cmd_count);
void	redirect_infile(t_vars *vars, t_cmd *command);
void	redirect_outfile(t_vars *vars, t_cmd *command);
void	redirect_cmd(t_vars *vars, t_cmd *command);

/* process_commands.c */
void	process_commands(t_vars *vars);
void	launch_exec_process(t_vars *vars, int i);
void	pipex(t_vars *vars, t_cmd *command);
void	execute_command(t_cmd *command, char **envp);

/* free_cmd.c */
void	free_cmd_array(t_cmd **command);
void	free_cmd_content(t_cmd **command, int cmd_count);
void	free_cmd_with_path(t_cmd **command, int	count);

/* free_path.c */
void	free_path_array(char **exec_path);

#endif