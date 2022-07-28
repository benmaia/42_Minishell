/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:16:30 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/28 04:43:49 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

int	path_tester_cmd(t_data *d, int i, char *tmp)
{
	t_promp	*tmp_p;
	int		j;

	tmp_p = d->p;
	if (!tmp_p->path)
		return (1);
	while (tmp_p->path[++i])
	{
		tmp = ft_strjoin(tmp_p->path[i], d->p->cmd_path);
		j = access(tmp, F_OK);
		if (j < 0)
			free (tmp);
		else
		{
			free (d->p->cmd_path);
			d->p->cmd_path = ft_strdup(tmp);
			free (tmp);
			return (0);
		}
		if (i >= (int)sizeof(tmp_p->path))
			break ;
	}
	return (1);
}

void	relative_cmd(t_data *d)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strdup(d->p->exe[0]);
	tmp = ft_strjoin("/", tmp2);
	d->p->cmd_path = ft_strdup(tmp);
	free (tmp);
	free (tmp2);
	if (path_tester_cmd(d, -1, tmp))
	{
		ft_putstr_fd("error: command not found\n", 2);
		g_err_value = CMD_NOT_FOUND_ERR;
	}
}

int	absolute_cmd(t_data *d)
{
	int	i;

	if (d->p->exe[0][0] != '/')
		return (1);
	d->p->cmd_path = ft_strdup(d->p->exe[0]);
	i = access(d->p->cmd_path, F_OK);
	if (i < 0)
	{
		ft_putstr_fd("error: command not found\n", 2);
		g_err_value = CMD_NOT_FOUND_ERR;
	}
	return (0);
}

void	find_path(t_data *d)
{
	char	*tmp;
	t_list	*env_tmp;

	tmp = NULL;
	env_tmp = d->env;
	while (env_tmp)
	{
		if (!ft_strncmp((char *)env_tmp->content, "PATH=", 5))
			tmp = ft_strdup((char *)env_tmp->content + 5);
		env_tmp = env_tmp->next;
	}
	if (!tmp)
	{
		ft_putstr_fd("error: no such file or directory\n", 2);
		g_err_value = FILE_DIR_ERR;
		free (tmp);
		exit (FILE_DIR_ERR) ;
	}
	d->p->path = ft_split(tmp, ':');
	free (tmp);
}
