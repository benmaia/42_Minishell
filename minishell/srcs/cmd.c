/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:16:30 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 14:39:46 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*This function, will test a PATH with*/
/*the given command until it gets the*/
/*right path, or until there is no more*/
/*PATH to check with, if it find the*/
/*correct PATH, it will save that command*/
/*in the d->p->cmd to send it to execve*/
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
	}
	return (1);
}

/*If the absolute command function*/
/*return (0), then we will concatenate*/
/*a '/' to pass it to the path tester*/
/*function to check if the command exists*/
void	relative_cmd(t_data *d)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strdup(d->p->exe[0]);
	tmp = ft_strjoin("/", tmp2);
	d->p->cmd_path = ft_strdup(tmp);
	free (tmp);
	free (tmp2);
	if (!ft_strcmp(d->p->exe[0], "export"))
		return ;
	if (path_tester_cmd(d, -1, tmp))
	{
		ft_putstr_fd("error: command not found\n", 2);
		g_err_value = CMD_NOT_FOUND_ERR;
	}
}

/*If it's an absolute command*/
/*it won't attatch a PATH behind*/
/*to test it, it just tests command*/
/*with the given path, if its wrong*/
/*gives an error and returns (0), if*/
/*it's not an absolute command it will*/
/*also return (0), and if it is an absolute*/
/*command it returns (1)*/
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

/*This function will grab the PATH*/
/*on the element with the PATH store*/
/*and store it in a double pointer*/
/*to be easier to attacht paths to the*/
/*command, so check it the paths is correct*/
void	find_path(t_data *d)
{
	char	*tmp;
	t_list	*env_tmp;

	tmp = NULL;
	env_tmp = d->env;
	if (!d->p->exe[0] || !ft_strncmp(d->p->exe[0], "/", 1))
		return ;
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
		exit (FILE_DIR_ERR);
	}
	d->p->path = ft_split(tmp, ':');
	free (tmp);
}
