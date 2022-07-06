/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:29:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/06 05:51:47 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	ft_export(t_data *d)
{
	t_list	*new_var;

	if (ft_strncmp(d->buf, "export ", 7))
		perror("error");
	else
	{
		check_spaces(d, -1);
		new_var = ft_lstnew(d->buf);
		ft_lst_strprint(new_var);
		ft_lstadd_back(&d->env, new_var);
	}
}
