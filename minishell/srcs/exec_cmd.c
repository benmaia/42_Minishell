/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:08:31 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/23 23:20:10 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	cmds_exec(t_data *d)
{
	t_list	*tmp;
	char	**envp;
	int		i;

	envp = (char **)malloc (sizeof(char *) * (ft_lstsize(d->env) + 1));
	d->p->exe = ft_split(d->p->cmd, ' ');
	find_path(d);
	i = 0;
	tmp = d->env;
	while (tmp)
	{
		envp[i] = ft_strdup((char *)tmp->content);
		i++;
		tmp = tmp->next;
	}
	envp[i] = NULL;
	if (!ft_strncmp(d->p->exe[0], "./", 2))
		d->p->cmd_path = ft_strdup(d->p->exe[0]);
	else if (absolute_cmd(d))
		relative_cmd(d);
	i = execve(d->p->cmd_path, d->p->exe, envp);
}

int	built_in(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "export", 6))
	{
		ft_export(d);
		return (0);
	}
	quotes(d, -1);
	if (!ft_strncmp(d->p->cmd, "unset", 5))
		ft_unset(d);
	else if (!ft_strncmp(d->p->cmd, "pwd", 3))
		ft_pwd(d);
	else if (!ft_strncmp(d->p->cmd, "env", 3))
		ft_env(d);
	else if (!ft_strncmp(d->p->cmd, "cd", 2))
		cd(d);
	else if (!ft_strncmp(d->p->cmd, "echo", 4))
		ft_echo(d);
	else if (!ft_strncmp(d->p->cmd, "exit\0", 5))
	{
		free (d->buf);
		ft_free_stack(&d->env);
		exit (1);
	}
	else
		return (1);
	return (0);
}
