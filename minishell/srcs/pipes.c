/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:28:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/24 17:43:59 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	piping(t_data *d, int x)
{
	pid_t	pid;
	int	pipes[2];
	int	i;

	if (pipe(pipes) == -1)
		perror("error");
	pid = fork();
	if (pid < 0)
		perror("error");
	if (!pid)
	{
		close(pipes[0]);
		if (x != d->nbr_cmd)
			dup2(pipes[1], STDOUT_FILENO);
		i = built_in(d);
		if (i == 1)
			exit (1);
		else
			cmds_exec(d);
	}
	close(pipes[1]);
	wait(NULL);
	if (x != d->nbr_cmd)
		dup2(pipes[0], STDIN_FILENO);
}
