/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:28:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 15:05:00 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Changes the STDIN and STDOUT of the*/
/*program to where it needs to be*/
/*If it's the 1st command, closes the pipe 0*/
/*to wait for manual input if need it*/
/*if it's not the first then STDIN will be*/
/*changed to an fd to read the output*/
/*of the command before, the output is changed*/
/*to the pipe 1 if it's not the last command*/
void	changing_dup(t_data *d, int x, int i)
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
		exit (0);
	else if (i == 1)
		cmds_exec(d, 0);
}

/*Creates the pipe and the fork for the*/
/*child process to run, also change the signals*/
/*from prompt to block*/
void	piping(t_data *d, int x)
{
	int	i;

	if (pipe(d->pp->pipes) == -1)
		perror("error");
	d->pp->pid = fork();
	if (d->pp->pid < 0)
		perror("error");
	signal_block();
	if (!d->pp->pid)
		changing_dup(d, x, i);
	close(d->pp->pipes[1]);
	waitpid(d->pp->pid, &i, 0);
	if (i == 256)
		g_err_value = NO_ERROR;
	else
		g_err_value = i / 256;
	d->pp->pipe_fd = d->pp->pipes[0];
}
