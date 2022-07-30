/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:47:01 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/30 22:24:48 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

static int	simple(char *d, int i)
{
	i++;
	while (d[i] != '\'' && d[i])
		i++;
	return (i);
}

static int	doublee(char *d, int i)
{
	i++;
	while (d[i] != '\"' && d[i])
		i++;
	return (i);
}

static void	checker(t_promp *tmp, int i)
{
	if (tmp->cmd[i] == '&'
		|| tmp->cmd[i] == '|'
		|| !tmp->cmd[i])
		ft_putstr_fd("bash: syntax error near unexpected token\n", 2);
}

/*Seaches for a token in the cmd and*/
/*if it finds it, puts the token in the*/
/*token variable and cleans the cmd*/
static void	parse_exec(t_promp *tmp, int i, char *tmpstr)
{
	while (tmp->cmd[++i])
	{
		checker(tmp, i);
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
}

void	parsing_tokens(t_promp *p, int i)
{
	t_promp	*tmp;
	char	*tmpstr;

	tmp = p;
	tmpstr = NULL;
	while (tmp)
	{
		parse_exec(tmp, i, tmpstr);
		tmp = tmp->next;
	}
}
