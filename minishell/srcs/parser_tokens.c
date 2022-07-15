/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:47:01 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/11 16:18:17 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

int	tokenizer(char	c)
{
	if (c == '>')
		return (1);
	else if (c == '<')
		return (1);
		/*return (1);*/
		/*return (1);*/
	else
		return (0);
}

/*Seaches for a token in the cmd and*/
/*if it finds it, puts the token in the*/
/*token variable and cleans the cmd*/
void	parsing_tokens(t_promp **p)
{
	t_promp	*tmp;
	char		*tmpstr;
	int		i;

	tmp = *p;
	while (tmp)
	{
		i = -1;
		while (tmp->cmd[++i])
		{
			if (tokenizer(tmp->cmd[i]))
			{
				tmpstr = ft_substr(tmp->cmd, 0, i - 1);
				tmp->token = ft_substr(tmp->cmd, i, ft_strlen(tmp->cmd));
				free (tmp->cmd);
				tmp->cmd = ft_strdup(tmpstr);
				free (tmpstr);
				break ;
			}
		}
		tmp = tmp->next;
	}
}
