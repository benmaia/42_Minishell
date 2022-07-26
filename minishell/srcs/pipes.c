/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:28:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/26 23:54:07 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	piping(t_data *d, int x)
{
	int	i;
	int	j;

	if (pipe(d->pp->pipes) == -1)
		perror("error");
	d->pp->pid = fork();
	if (d->pp->pid < 0)
		perror("error");
	if (!d->pp->pid)
	{
		if (x == 1)
			close(d->pp->pipes[0]);
		else if (x > 1)
		{
			dup2(d->pp->pipe_fd, STDIN_FILENO);
			close(d->pp->pipe_fd);
		}
		if (x != d->nbr_cmd)
			dup2(d->pp->pipes[1], STDOUT_FILENO);
		i = built_in(d);
		if (i == 0)
			exit (i);
		else if (i == 1)
			cmds_exec(d);
	}
	close(d->pp->pipes[1]);
	waitpid(d->pp->pid, &j, 0);
	g_err_value = j/256;
	d->pp->pipe_fd = d->pp->pipes[0];
}
