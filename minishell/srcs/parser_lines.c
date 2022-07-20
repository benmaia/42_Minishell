/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:01:59 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/17 17:02:53 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

/*Just skips everything until finding*/
/*a double quote, and returns it's position*/
static int	doublee(t_data *d, int i)
{
	i++;
	while (d->buf[i] != '\"')
		i++;
	return (i);
}

/*Just skips everything until finding*/
/*a simple quote, and returns it's position*/
static int	simple(t_data *d, int i)
{
	i++;
	while (d->buf[i] != '\'')
		i++;
	return (i);
}

/*Recieves the prompt, and divides the*/
/*prompt into elements on a linked list*/
/*everytime it finds a pipe.*/
/*It checks for quotes to ignore the pipes*/
/*between quotes, and calls a doublee or simple*/
/*function to handle them.*/
/*After checks for a space in the first position*/
/*and if it finds it, it iterates one*/
/*position to skip useless spaces*/
t_promp	*parser_promp(t_data *d, int i)
{
	t_promp	*promp;
	int		j;

	promp = NULL;
	j = 0;
	while (d->buf[++i])
	{
		if (d->buf[i] == '\"')
			i = doublee(d, i);
		else if (d->buf[i] == '\'')
			i = simple(d, i);
		else if (d->buf[i] == '|')
		{
			if (d->buf[j] == ' ')
				j++;
			ft_prompadd(&promp, ft_prompnew(ft_substr(d->buf, j, i - j)));
			j = i + 1;
		}
	}
	if (d->buf[j] == ' ')
		j++;
	ft_prompadd(&promp, ft_prompnew(ft_substr(d->buf, j, i - j)));
	return (promp);
}
