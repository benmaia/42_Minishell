/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:29:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 14:53:35 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*It's a function made to when it found a quote*/
/*just delete the quote of the string and keeps*/
/*skipping all chars in a string until if finds */
/*another quote of the same type, and remove it */
/*from the string as well*/
/*It returns the index where the quotes stopped*/
int	export_quotes(char *tmp, int i)
{
	if (tmp[i] == '\"')
	{
		ft_memmove(&tmp[i], &tmp[i + 1], ft_strlen(tmp) - 1);
		while (tmp[i] != '\"')
			i++;
		ft_memmove(&tmp[i], &tmp[i + 1], ft_strlen(tmp) - 1);
		i--;
	}
	else if (tmp[i] == '\'')
	{
		ft_memmove(&tmp[i], &tmp[i + 1], ft_strlen(tmp) - 1);
		while (tmp[i] != '\'')
			i++;
		ft_memmove(&tmp[i], &tmp[i + 1], ft_strlen(tmp) - 1);
		i--;
	}
	return (i);
}

/*This function it will create a tmp var*/
/*to store the input of the command and */
/*so it can find spaces, if it find spaces*/
/*outside quotes it will change the input in*/
/*prompt to the first space, ignoring what is*/
/*after he spaces, if it finds quotes first*/
/*it will call the export_quotes function so*/
/*the spaces can be ignored*/
void	check_spaces(t_data *d, int i)
{
	char	*tmp;

	tmp = ft_strdup(ft_strchr(d->buf, ' ') + 1);
	while (tmp[++i])
	{
		i = export_quotes(tmp, i);
		if (tmp[i] == ' ')
		{
			free (d->buf);
			d->buf = ft_substr(tmp, 0, i);
			free (tmp);
			return ;
		}
	}
	if (tmp[i] == '\0')
	{
		free (d->buf);
		d->buf = ft_strdup(tmp);
		free (tmp);
		return ;
	}
	free (tmp);
}

/*Just to check if the input it's valid or not*/
/*the variable name as to be followed by an "="*/
/*or the input is invalid and returns 0*/
/*if the input is valid it will return 1*/
int	checker(t_data *d, int i)
{
	while (d->buf[++i])
	{
		if (d->buf[i] == ' ')
		{
			perror("error");
			return (0);
		}
		else if (d->buf[i] == '=')
			return (1);
	}
	if (d->buf[i] == '\0')
	{
		g_err_value = FILE_DIR_ERR;
		ft_putstr_fd("error: no such file or directory\n", 2);
	}
	return (0);
}

/*Part 2 of ft_export, it checks if there*/
/*is any duplicates or errors in the syntax*/
static void	else_norminette(t_data *d)
{
	t_list	*new_var;

	check_spaces(d, -1);
	if (checker(d, -1))
	{
		if (export_check_duplicates(d))
		{
			myfree((void *)&d->buf);
			g_err_value = NO_ERROR;
			return ;
		}
		new_var = ft_lstnew(ft_strdup(d->buf));
		ft_lstadd_back(&d->env, new_var);
		myfree((void *)&d->buf);
		g_err_value = NO_ERROR;
	}
}

/*Replicates the exportion function on bash*/
/*it adds enviroment variables or changes*/
/*their value to the right input*/
/*It also does a specific parsing needed*/
/*for that it calls the funtions, check_spaces*/
/*checker and check_duplicates and after that*/
/*creates a new element if the check_duplicates*/
/*returns 0 or changes it's value if it returns 1*/
void	ft_export(t_data *d)
{
	if (ft_strncmp(d->buf, "export ", 7))
	{
		if (!ft_strcmp(d->buf, "export"))
			ft_lst_strprint(d->env);
		else
		{
			ft_putstr_fd("error: command not found\n", 2);
			g_err_value = CMD_NOT_FOUND_ERR;
		}
	}
	else
		else_norminette(d);
}
