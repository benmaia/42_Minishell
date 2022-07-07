/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:50:14 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/06 23:53:20 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/env.h"
#include "../inc/minishell.h"
#include <stdio.h>

void	ft_free_stack(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (!list)
		return ;
	current = *list;
	while (current != NULL)
	{
		next = current->next;
		free (current->content);
		free (current);
		current = next;
	}
	*list = NULL;
}

t_list	*init_env(char **envp)
{
	t_list	*env;
	int i;

	i = 0;
	env = ft_lstnew(ft_strdup(envp[i]));
	env->next = NULL;
	while (envp[++i])
		ft_lstadd_back(&env, ft_lstnew(ft_strdup(envp[i])));
	return (env);
}

void	ft_env(t_data *d)
{
	if (!ft_strncmp(d->buf, "env\0", 4) || !ft_strncmp(d->buf, "env ", 4))
		ft_lst_strprint(d->env);
	else
		perror("error");
}
