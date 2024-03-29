/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:09:26 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 14:49:50 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Same as the error_handler_exit, part2*/
/*Handles the exit errors, more then 1*/
/*argument, and a non int argument*/
char	*error_exit(char *tmp, int i)
{
	if (!ft_isdigit(tmp[i + 1]))
	{
		ft_putstr_fd("exit\nbash: exit: numeric argument required\n", 2);
		exit (2);
	}
	else
	{
		ft_putstr_fd("exit\nbash: exit: too many arguments\n", 2);
		g_err_value = 1;
	}
	free (tmp);
	tmp = NULL;
	return (tmp);
}

/*Handles the exit errors, more then 1*/
/*argument, and a non int argument*/
static char	*error_handler_exit(t_data *d, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strdup(ft_strchr(d->p->cmd, ' ') + 1);
	tmp = ft_strtrim(tmp2, " ");
	free (tmp2);
	if (!ft_isalpha(tmp[i]))
		while (tmp[i] != ' ' && tmp[i])
			i++;
	if (tmp[i] != '\0')
		tmp = error_exit(tmp, i);
	return (tmp);
}

/*When this function is called*/
/*it frees all the allocated memory*/
/*before exits the program*/
void	ft_exit(t_data *d)
{
	char	*tmp;
	int		exit_value;

	if (!ft_strcmp(d->p->cmd, "exit"))
	{
		myfree((void *) &d->buf);
		ft_free_stack(&d->env);
		exit(g_err_value);
	}
	else
	{
		tmp = error_handler_exit(d, 0);
		if (tmp)
		{
			exit_value = ft_atoi(tmp);
			myfree((void *) &d->buf);
			ft_free_stack(&d->env);
			free (tmp);
			exit (exit_value);
		}
	}
}
