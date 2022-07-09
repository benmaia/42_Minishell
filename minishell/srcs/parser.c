/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:01:59 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/08 00:00:23 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

int	doublee(t_data *d, int i)
{
	i++;
	while (d->buf[i] != '\"')
		i++;
	return (i);
}

int	simple(t_data *d, int i)
{
	i++;
	while (d->buf[i] != '\'')
		i++;
	return (i);
}

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
			ft_prompadd(&promp, ft_prompnew(ft_substr(d->buf, j, i - j)));
			j = i + 1;
		}
	}
	ft_prompadd(&promp, ft_prompnew(ft_substr(d->buf, j, i - j)));
	return (promp);
}
