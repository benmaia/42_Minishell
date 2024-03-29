/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:08:31 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 14:47:35 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*If it's not a built-in then it will*/
/*return (1) and enter in this function*/
/*where I create a copy of the env but to*/
/*a double pointer to send it to execve*/
/*after I'll split the command in a double*/
/*pointer, also to send it to execve*/
/*and then it will try to find the right*/
/*command path to send it also to execve*/
/*if exevce fails, have an exit with protection*/
void	cmds_exec(t_data *d, int i)
{
	t_list	*tmp;

	d->p->envp = (char **)malloc (sizeof(char *) * (ft_lstsize(d->env) + 1));
	d->p->exe = ft_split(d->p->cmd, ' ');
	find_path(d);
	tmp = d->env;
	while (tmp)
	{
		d->p->envp[i++] = ft_strdup((char *)tmp->content);
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
	exit(CMD_NOT_FOUND_ERR);
}

/*Checks if it's export command because the*/
/*export have a different parser then the others*/
/*if it's not it will do a general parsing for all*/
/*the commands with the function quotes*/
/*and checks if it's a built-in, if it is*/
/*it runs the command and return (0), otherwise*/
/*it will return (1)*/
int	env_cmd(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "export", 6))
		ft_export(d);
	quotes(d, -1);
	if (!ft_strncmp(d->p->cmd, "unset", 5))
		ft_unset(d);
	else if (!ft_strncmp(d->p->cmd, "cd", 2))
		cd(d);
	else if (!ft_strncmp(d->p->cmd, "exit", 4))
		ft_exit(d);
	else
		return (0);
	return (1);
}

/*Changes the signals to block command signals*/
/*and checks if it's a built-in, if it is*/
/*it runs the command and return (0), otherwise*/
/*it will return (1)*/
int	built_in(t_data *d)
{
	signal_block();
	if (!ft_strncmp(d->p->cmd, "pwd", 3))
		ft_pwd(d);
	else if (!ft_strncmp(d->p->cmd, "env", 3))
		ft_env(d);
	else if (!ft_strncmp(d->p->cmd, "echo", 4))
		ft_echo(d);
	else
		return (1);
	return (0);
}
