/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:02:59 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/28 23:31:59 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/readline.h>
#include <stdio.h>

/*Just skips everything until finding*/
/*a double quote, and returns it's position*/
static int	doublee(t_data *d, int i)
{
	i++;
	while (d->buf[i] != '\"' && d->buf[i])
		i++;
	return (i);
}

/*Just skips everything until finding*/
/*a simple quote, and returns it's position*/
static int	simple(t_data *d, int i)
{
	i++;
	while (d->buf[i] != '\'' && d->buf[i])
		i++;
	return (i);
}

static void	checker(t_data *d)
{
	if (!d->buf)
	{
		g_err_value = CMD_NOT_FOUND_ERR;
		exit (1);
	}
}

int	edge_quotes(t_data *d)
{
	int	i;

	i = 0;
	i = ft_isspacestr(d->buf);
	if (i == 0)
	{
		free (d->buf);
		return (1);
	}
	if (!ft_strcmp(d->buf, "\"") || !ft_strcmp(d->buf, "\'")
		|| !ft_strcmp(d->buf, "\"\"") || !ft_strcmp(d->buf, "''"))
		free (d->buf);
	else if (!ft_strncmp(d->buf, "||", 2) || !ft_strncmp(d->buf, "| ", 2)
		|| !ft_strncmp(d->buf, "|\0", 2))
	{
		g_err_value = 2;
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
	}
	else
		return (0);
	return (1);
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
	checker(d);
	j = 0;
	if (edge_quotes(d))
		return (NULL);
	while (d->buf[++i])
	{
		if (d->buf[i] == '\"')
			i = doublee(d, i);
		else if (d->buf[i] == '\'')
			i = simple(d, i);
		else if (d->buf[i] == '|')
		{
			ft_prompadd(&promp, ft_prompnew(ft_substr(d->buf, j, i - j)));
			j = i + 1;
		}
	}
	while (d->buf[j] == ' ')
		j++;
	ft_prompadd(&promp, ft_prompnew(ft_substr(d->buf, j, i - j)));
	return (promp);
}
