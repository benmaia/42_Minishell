/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:50:14 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/06 00:29:42 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/env.h"
#include "../inc/minishell.h"
#include <stdio.h>

t_list	*init_env(char **envp)
{
	t_list	*env;
	t_list	*tmp;
	int i;

	i = -1;
	while (envp[++i])
	{
		if (i == 0)
		{
			env = ft_lstnew(ft_strdup(envp[i]));
			env->next = tmp;
			tmp = env;
		}
		else
		{
			tmp->next = ft_lstnew(ft_strdup(envp[i]));
			tmp = tmp->next;
		}
	}
	tmp->next = NULL;
	return (env);
}

void	ft_env(t_data *d)
{
	if (!ft_strncmp(d->buf, "env\0", 4) || !ft_strncmp(d->buf, "env ", 4))
		ft_lst_strprint(d->env);
	else
		perror("error");
}
