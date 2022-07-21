/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:28:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/21 03:28:22 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <unistd.h>

void	child_process(t_data *d)
{
	close (d->ps->pipe[0]);
	dup2 (d->ps->pipe[1], STDOUT_FILENO);
	if (built_in(d))
		printf("exec\n");
	close (d->ps->pipe[1]);
	/*wait (NULL);*/
	dup2 (d->ps->pipe[0], STDIN_FILENO);
}

void	change_dups(t_data *d)
{
	if (pipe(d->ps->pipe) == -1)
	{
		perror("error");
		err_value = OUT_RANGE_ERR; 
	}
	d->ps->pid = fork();
	if (d->ps->pid < 0)
	{
		perror("error");
		err_value = OUT_RANGE_ERR; 
	}
	if (!d->ps->pid)
	{
		child_process(d);
		printf("trtrt\n");
	}
}

int	pipes(t_data *d)
{
	if (d->p->next)
		return (1);
	return (0);
}
