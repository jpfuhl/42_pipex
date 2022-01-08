/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 07:42:34 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 20:50:37 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc != 5)
	{
		write(2, "Correct input: ./pipex infile cmd1 cmd2 outfile\n", 49);
		exit (EXIT_WRONG_INPUT);
	}
	vars.envp = envp;
	vars.cmd_count = argc - 3;
	open_files(&vars, argc, argv);
	parse_commands(&vars, argv, vars.cmd_count);
	parse_exec_paths(&vars, envp);
	redirect_streams(&vars, vars.command, vars.cmd_count);
	process_commands(&vars);
	free_cmd_with_path(vars.command, vars.cmd_count);
	free_cmd_content(vars.command, vars.cmd_count);
	free_cmd_array(vars.command);
	free_path_array(vars.exec_path);
	return (0);
}
