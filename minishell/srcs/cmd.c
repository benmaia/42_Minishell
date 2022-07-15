/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:08:31 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/15 01:46:03 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <string.h>

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
		ft_pwd();
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
		/*free_prompt(&d->p);*/
		exit (1);
	}
	else
		return (1);
	return (0);
}
