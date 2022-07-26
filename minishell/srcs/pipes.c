/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:28:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/26 02:24:11 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	piping(t_data *d, int x)
{
	/*pid_t	pid;*/
	/*int	pipes[2];*/
	int	i;

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
			dup2(d->pp->pipes[0], STDIN_FILENO);
		if (x != d->nbr_cmd)
			dup2(d->pp->pipes[1], STDOUT_FILENO);
		close(d->pp->pipes[1]);
		i = built_in(d);
		if (i == 0)
			exit (1);
		else if (i == 1)
			cmds_exec(d);
	}
	close(d->pp->pipes[1]);
	close(d->pp->pipes[0]);
	wait(NULL);
	/*dup2(d->pp->pipes[0], STDIN_FILENO);*/
}
