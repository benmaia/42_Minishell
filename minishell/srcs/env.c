/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:50:14 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/20 22:22:41 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/env.h"
#include "../inc/minishell.h"
#include <stdio.h>

/*It checks if the variable passed on the prompt*/
/*exists, and if it does, it return his value*/
char	*ft_check_var(t_list *list, char *var)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp((char *)tmp->content, var, ft_strlen(var)))
			return (ft_strchr(tmp->content, '=') + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

/*Once minishell it's closed, it will free all*/
/*the memory allocated to store the env even if*/
/*during the use of minishell you created, deleted*/
/*or edited some variables*/
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

/*It will create a single linked list and*/
/*store all the enviroment variables inside.*/
/*Every variable is in a different element */
/*and it will be by the order*/
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

/*Replicates the env function on bash, it*/
/*will get the enviroment variables of the pc*/
/*and then print them in order on the terminal*/
void	ft_env(t_data *d)
{
	if (!ft_strncmp(d->buf, "env\0", 4) || !ft_strncmp(d->buf, "env ", 4))
	{
		ft_lst_strprint(d->env);
		err_value = 0;
	}
	else
	{
		perror("error");
		err_value = CMD_NOT_FOUND_ERR;
	}
}
