/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:08:31 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/28 22:53:25 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	cmds_exec(t_data *d)
{
	t_list	*tmp;
	int		i;

	d->p->envp = (char **)malloc (sizeof(char *) * (ft_lstsize(d->env) + 1));
	d->p->exe = ft_split(d->p->cmd, ' ');
	find_path(d);
	i = 0;
	tmp = d->env;
	while (tmp)
	{
		d->p->envp[i] = ft_strdup((char *)tmp->content);
		i++;
		tmp = tmp->next;
	}
	d->p->envp[i] = NULL;
	if (!d->p->exe[0])
	{
		ft_putstr_fd("error: cmd not found\n", 2);
		exit(127);
	}
	if (!ft_strncmp(d->p->exe[0], "./", 2))
		d->p->cmd_path = ft_strdup(d->p->exe[0]);
	else if (absolute_cmd(d))
		relative_cmd(d);
	i = execve(d->p->cmd_path, d->p->exe, d->p->envp);
	exit(127);
}

int	env_cmd(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "export", 6))
	{
		ft_export(d);
		return (1);
	}
	quotes(d, -1);
	if (!ft_strncmp(d->p->cmd, "unset", 5))
	{
		ft_unset(d);
		return (1);
	}
	else if (!ft_strncmp(d->p->cmd, "cd", 2))
	{
		cd(d);
		return (1);
	}
	else if (!ft_strncmp(d->p->cmd, "exit\0", 5))
	{
		free (d->buf);
		ft_free_stack(&d->env);
		exit (NO_ERROR);
	}
	return (0);
}

int	built_in(t_data *d)
{
	signal_block();
	if (!ft_strncmp(d->p->cmd, "unset", 5))
		ft_unset(d);
	else if (!ft_strncmp(d->p->cmd, "pwd", 3))
		ft_pwd(d);
	else if (!ft_strncmp(d->p->cmd, "env", 3))
		ft_env(d);
	else if (!ft_strncmp(d->p->cmd, "echo", 4))
		ft_echo(d);
	else
		return (1);
	return (0);
}
