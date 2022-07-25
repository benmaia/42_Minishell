/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:47:01 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/23 13:08:27 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

static int	simple(char *d, int i)
{
	i++;
	while (d[i] != '\'')
		i++;
	return (i);
}

static int	doublee(char *d, int i)
{
	i++;
	while (d[i] != '\"')
		i++;
	return (i);
}

int	tokenizer(char c)
{
	if (c == '>')
		return (1);
	else if (c == '<')
		return (1);
	else
		return (0);
}

/*Seaches for a token in the cmd and*/
/*if it finds it, puts the token in the*/
/*token variable and cleans the cmd*/
void	parsing_tokens(t_promp *p, int i)
{
	t_promp	*tmp;
	char	*tmpstr;

	tmp = p;
	while (tmp)
	{
		while (tmp->cmd[++i])
		{
			if (tmp->cmd[i] == '\"')
				i = doublee(tmp->cmd, i);
			else if (tmp->cmd[i] == '\'')
				i = simple(tmp->cmd, i);
			if (tokenizer(tmp->cmd[i]))
			{
				tmpstr = ft_substr(tmp->cmd, 0, i - 1);
				tmp->pre_token = ft_substr(tmp->cmd, i, ft_strlen(tmp->cmd));
				free (tmp->cmd);
				tmp->cmd = ft_strdup(tmpstr);
				free (tmpstr);
				break ;
			}
		}
		i = -1;
		tmp = tmp->next;
	}
}
