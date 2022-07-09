/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/09 17:47:42 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

void	invalid_var(char *var)
{
	free (var);
	/*free (p);*/
	/*free (p1);*/
	/*free (p2);*/
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

	var = ft_substr(d->buf, j, i - j);
	if (!var)
	{
		invalid_var(var);
		return ;
	}
	p = ft_substr(d->buf, 0, j);
	p1 = ft_substr(d->buf, i, ft_strlen(d->buf));
	p2 = ft_strjoin(p, ft_check_var(d->env, var));
	p3 = ft_strjoin(p2, p1);
	free (d->buf);
	d->buf = ft_strdup(p3);
	free (p);
	free (p1);
	free (p2);
	free (p3);
	free (var);
}
/*This function, removes the $ sign*/
/*the string, saves the position where*/
/*the enviroment variable starts and ends*/
/*and then send everything to expand_var*/
/*so the expansion can be made*/
void	dollar_var(t_data *d, int i)
{
	int	j;

	ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
	j = i;
	while (d->buf[i] != ' ' && d->buf[i] != '\"'
		&& d->buf[i] != '\'' && d->buf[i])
			i++;
	expand_var(d, i, j);
}
