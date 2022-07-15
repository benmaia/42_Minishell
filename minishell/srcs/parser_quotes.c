/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:40:25 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/11 19:04:12 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

/*It will iterate the string until if finds*/
/*another double quote, ignoring everything*/
/*between them, execpt the $ sign!*/
/*If it find the $sign it will call the*/
/*expand_var function to expand the variable*/
int	double_quotes(t_data *d, int i)
{
	int	j;

	while (d->p->cmd[++i] != '\"' && d->p->cmd[i])
	{
		if (d->p->cmd[i] == '$')
		{
			ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
			j = i;
			while (d->p->cmd[i] != ' ' && d->p->cmd[i] != '\"'
				&& d->p->cmd[i] != '\'' && d->p->cmd[i])
				i++;
			if (d->p->cmd[i])
				expand_var(d, i, j);
			i--;
		}
	}
	return (i);
}

/*If it checks that thes more then 1 space*/
/*it removes those spaces, cleaning the string*/
void	clean_extra_spaces(t_data *d, int i)
{
	while (d->p->cmd[++i] == ' ')
	{
		ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
		i--;
	}
}

/*This function will check in every string*/
/*position if it finds a quote, a $ sign or*/
/*a space. If it finds a double quote it will*/
/*call the double_quotes function, if it's a*/
/*a single quote it will continue iterating*/
/*until find another simple quote, ignoring what*/
/*it between the single quotes. If it's a $ sign*/
/*it will call the dollar_var function to expand*/
/*the enviroment variable, and if it's a space*/
/*it will call the clean_extra_spaces function*/
/*to check if there is more then 1 space in a row*/
char	*quotes(t_data *d, int i)
{
	while (d->p->cmd[++i])
	{
		if (d->p->cmd[i] == '\"')
		{
			ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
			i = double_quotes(d, --i);
			ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
			i--;
		}
		else if (d->p->cmd[i] == '\'')
		{
			ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
			while (d->p->cmd[i] != '\'' && d->p->cmd[i])
				i++;
			ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
		}
		else if (d->p->cmd[i] == '$')
			dollar_var(d, i);
		else if (d->p->cmd[i] == ' ')
			clean_extra_spaces(d, i);
	}
	return (d->p->cmd);
}