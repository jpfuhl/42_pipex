/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:53:35 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/26 04:01:25 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_files(t_vars *vars, int argc, char **argv)
{
	int	len;

	vars->fd_infile = open(argv[1], O_RDONLY);
	if (vars->fd_infile == -1)
	{
		write(2, "zsh: no such file or directory: ", 33);
		len = ft_strlen(argv[1]);
		write(2, &(*argv[1]), len);
		write(2, "\n", 1);
		exit (EXIT_INFILE_OPEN_ERROR);
	}
	vars->fd_outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars->fd_outfile == -1)
	{
		write(2, "zsh: permission denied: ", 25);
		len = ft_strlen(argv[argc - 1]);
		write(2, &(*argv[argc - 1]), len);
		write(2, "\n", 1);
		exit (EXIT_OUTFILE_OPEN_ERROR);
	}
}
