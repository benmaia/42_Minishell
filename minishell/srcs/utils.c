/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:52:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 15:08:36 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*Checks if the enviroment variable given*/
/*on input already exists, if it does, it will*/
/*clean it's value and substitute for the new one*/
/*and retuns 1, if it doesn't exists it will return 0*/
/*so the ft_export can create and add a new elemnt on*/
/*the list with the new variable and it's value*/
int	export_check_duplicates(t_data *d)
{
	t_list	*tmp;
	char	*var;
	int		i;

	i = -1;
	while (d->buf[++i])
		if (d->buf[i] == '=')
			break ;
	var = ft_substr(d->buf, 0, i);
	tmp = d->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, var, ft_strlen(var)))
		{
			free (var);
			free (tmp->content);
			tmp->content = ft_strdup(d->buf);
			return (1);
		}
		tmp = tmp->next;
	}
	free (var);
	return (0);
}

/*Checks if there is a redirection*/
/*or heredoc, to to the parser token*/
int	tokenizer(char c)
{
	if (c == '>')
		return (1);
	else if (c == '<')
		return (1);
	else
		return (0);
}
