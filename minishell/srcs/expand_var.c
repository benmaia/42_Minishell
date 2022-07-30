/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/29 23:58:00 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <ctype.h>
#include <stdio.h>

static char	*check_var(t_data *d, int i, int j)
{
	char	*var;
	char	*tmp;

	var = ft_substr(d->p->cmd, j, i - j);
	if (!var || !ft_check_var(d->env, var))
	{
		tmp = ft_substr(d->p->cmd, 0, j);
		free (var);
		free (d->p->cmd);
		d->p->cmd = ft_strjoin(tmp, " ");
		free (tmp);
		return (NULL);
	}
	return (var);
}

/*This functions, gets a copy of the promp*/
/*to where the enviroment variable is*/
/*gets a copy of the end of the enviroment*/
/*variable to the final of the string, and it*/
/*gets the value of the enviroment variable*/
/*that the prompt returned, after that it*/
/*concatenate everything put together to expand*/
/*the enviroment variable*/
void	expand_var(t_data *d, int i, int j)
{
	char	*var;
	char	*p;
	char	*p1;
	char	*p2;
	char	*p3;

	var = check_var(d, i, j);
	if (!var)
		return ;
	p = ft_substr(d->p->cmd, 0, j);
	p1 = ft_substr(d->p->cmd, i, ft_strlen(d->p->cmd));
	p2 = ft_strjoin(p, ft_check_var(d->env, var));
	p3 = ft_strjoin(p2, p1);
	free (d->p->cmd);
	d->p->cmd = ft_strdup(p3);
	free (p);
	free (p1);
	free (p2);
	free (p3);
	free (var);
}

static void	error_value(t_data *d, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*itoaa;

	ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
	tmp = ft_substr(d->p->cmd, 0, i);
	tmp2 = ft_substr(d->p->cmd, i, ft_strlen(d->p->cmd));
	free (d->p->cmd);
	itoaa = ft_itoa(g_err_value);
	tmp3 = ft_strjoin(tmp, itoaa);
	d->p->cmd = ft_strjoin(tmp3, tmp2);
	free (tmp);
	free (tmp2);
	free (tmp3);
	free (itoaa);
}

/*This function, removes the $ sign*/
/*the string, saves the position where*/
/*the enviroment variable starts and ends*/
/*and then send everything to expand_var*/
/*so the expansion can be made*/
void	dollar_var(t_data *d, int i)
{
	int	j;

	ft_memmove(&d->p->cmd[i], &d->p->cmd[i + 1], ft_strlen(d->p->cmd) - 1);
	j = i;
	if (d->p->cmd[i] == '?')
		error_value(d, i);
	else if (!isalpha(d->p->cmd[i]))
	{
		ft_putstr_fd("error: no such file or directory:\n", 2);
		g_err_value = FILE_DIR_ERR;
		return ;
	}
	else
	{
		while (d->p->cmd[i] != ' ' && d->p->cmd[i] != '\"'
			&& d->p->cmd[i] != '\'' && d->p->cmd[i] && d->p->cmd[i] != '$')
				i++;
		expand_var(d, i, j);
	}
}
