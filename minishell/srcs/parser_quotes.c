/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:40:25 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/30 01:59:33 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*It ignores everything between the simple quotes*/
/*and removes them from the command, to be printed*/
/*as it should*/
int	simple_quotes(t_data *d, int i)
{
	char	*tmp;
	int		j;

	j = i;
	i++;
	while (d->p->cmd[i] != '\'' && d->p->cmd[i])
		i++;
	tmp = ft_strdup(d->p->cmd);
	ft_memmove(&tmp[j], &tmp[j + 1], ft_strlen(tmp) - 1);
	ft_memmove(&tmp[i - 1], &tmp[i], ft_strlen(tmp) - 1);
	free (d->p->cmd);
	d->p->cmd = ft_strdup(tmp);
	free (tmp);
	return (i - 2);
}

/*It will iterate the string until if finds*/
/*another double quote, ignoring everything*/
/*between them, execpt the $ sign!*/
/*If it find the $sign it will call the*/
/*dollar_var function to expand the variable*/
int	double_quotes(t_data *d, int i)
{
	char	*tmp;
	int		j;

	j = i;
	while (d->p->cmd[++i] != '\"' && d->p->cmd[i])
	{
		if (d->p->cmd[i] == '$')
		{
			dollar_var(d, i);
			i--;
		}
	}
	tmp = ft_strdup(d->p->cmd);
	ft_memmove(&tmp[j], &tmp[j + 1], ft_strlen(tmp) - 1);
	ft_memmove(&tmp[i - 1], &tmp[i], ft_strlen(tmp) - 1);
	free (d->p->cmd);
	d->p->cmd = ft_strdup(tmp);
	free (tmp);
	return (i - 2);
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

/*Looks for edge cases to protect from crashes*/
int	edge_cases(t_data *d)
{
	if (!ft_strcmp(d->p->cmd, "\"")
		|| !ft_strcmp(d->p->cmd, "\'"))
	{
		free (d->p->cmd);
		d->p->cmd = ft_strdup("");
	}
	else if (!ft_strncmp(d->p->cmd, "||", 2)
		|| !ft_strncmp(d->p->cmd, "| ", 2)
		|| !ft_strncmp(d->p->cmd, "|\0", 2))
	{
		g_err_value = 2;
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
	}
	else
		return (0);
	return (1);
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
		if (edge_cases(d))
			return (NULL);
		if (d->p->cmd[i] == '\"')
			i = double_quotes(d, i);
		else if (d->p->cmd[i] == '\'')
			i = simple_quotes(d, i);
		else if (d->p->cmd[i] == '$')
			dollar_var(d, i);
		else if (d->p->cmd[i] == ' ')
			clean_extra_spaces(d, i);
	}
	return (d->p->cmd);
}
