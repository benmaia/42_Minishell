/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:57:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/23 13:08:57 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

/*Checks if the size of the content (x)*/
/*or the variable (var) and returns the */
/*size of the bigger one*/
int	check_size(int x, int z)
{
	if (x > z)
		return (x);
	else
		return (z);
}

/*Returns the position of the value*/
/*of the variable, skipping it's name*/
static int	content_size(char *content, int i)
{
	while (content[++i])
	{
		if (content[i] == '=')
			return (i);
	}
	return (i);
}

/*Check if the variable to delete is on the*/
/*head of the list, if it is, changes the head*/
/*and removes that element of the list*/
static void	check_head(t_data *d, char *var, t_list **tmp, t_list **next)
{
	t_list	**head;

	head = &d->env;
	if (!ft_strncmp((*head)->content, var, ft_strlen(var)))
	{
		*next = *head;
		*head = (*head)->next;
		*tmp = (*tmp)->next;
		free ((*next)->content);
		free (*next);
	}
}

/*First it will check if the variable to unset*/
/*is the first enviroment variable (the head of the list)*/
/*with the check_head function, if it is, that function*/
/*will unset that variable for us, and it's done*/
/*If it's not, it will check every element on the list*/
/*looking for the one storing the right variable and*/
/*remove it from the list when it found it*/
static void	unset_var(t_data *d, char *var)
{
	t_list	*tmp;
	t_list	*next;

	tmp = d->env;
	next = NULL;
	check_head(d, var, &tmp, &next);
	while (tmp->next)
	{
		if (!ft_strncmp(tmp->next->content, var,
				check_size(ft_strlen(var),
					content_size(tmp->next->content, -1))))
		{
			next = tmp->next;
			tmp->next = tmp->next->next;
			free (next->content);
			free (next);
			break ;
		}
		tmp = tmp->next;
	}
}

/*Replicates the unset function in bash*/
/*it will get the variable and call the*/
/*uset_var to check and delete the */
/*enviroment variable if exists*/
void	ft_unset(t_data *d)
{
	char	*var;

	if (!ft_strncmp(d->p->cmd, "unset\0", 6)
		|| !ft_strncmp(d->p->cmd, "unset ", 6))
	{
		var = ft_strdup(ft_strchr(d->p->cmd, ' ') + 1);
		unset_var(d, var);
		free (var);
		g_err_value = 0;
	}
	else
	{
		perror("error");
		g_err_value = CMD_NOT_FOUND_ERR;
	}
}
