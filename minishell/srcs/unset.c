/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:57:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/07 20:40:52 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

int	check_size(int x, int z)
{
	if (x > z)
		return (x);
	else
		return (z);
}

int	content_size(char *content, int i)
{
	while (content[++i])
	{
		if (content[i] == '=')
			return (i);
	}
	return (i);
}

void	check_head(t_data *d, char *var, t_list **tmp, t_list **next)
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

void	check_var(t_data *d, char *var)
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

void	ft_unset(t_data *d)
{
	char	*var;

	if (!ft_strncmp(d->buf, "unset\0", 6)
		|| !ft_strncmp(d->buf, "unset ", 6))
	{
		var = ft_strdup(ft_strchr(d->buf, ' ') + 1);
		check_var(d, var);
		free (var);
	}
	else
	{
		perror("error");
	}
}
