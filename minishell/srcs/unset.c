/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:57:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/07 17:33:49 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

void	check_var(t_data *d, char *var)
{
	t_list	*tmp;
	t_list	*next;

	tmp = d->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->next->content, var, ft_strlen(var)))
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
