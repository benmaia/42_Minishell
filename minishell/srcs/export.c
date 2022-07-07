/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:29:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/07 18:41:31 by bmiguel-         ###   ########.fr       */
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

int	checker(t_data *d, int i)
{
	while (d->buf[++i])
	{
		if (d->buf[i] == ' ')
		{
			perror("error");
			return (0);
			/*exit(1);*/
		}
		else if (d->buf[i] == '=')
			return (1);
	}
	if (d->buf[i] == '\0')
	{
		perror("error2");
		/*exit(1);*/
	}
	return (0);
}

int	check_duplicates(t_data *d)
{
	t_list	*tmp;
	char	*var;
	int		i;

	i = -1;
	while (d->buf[++i])
	{
		if (d->buf[i] == '=')
			break ;
	}
	var = ft_substr(d->buf, 0, i);
	tmp = d->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, var, ft_strlen(var)))
		{
			free (var);
			free (tmp->content);
			tmp->content = ft_strdup(d->buf);
			return (1);
		}
		tmp = tmp->next;
	}
	free (var);
	return (0);
}

void	ft_export(t_data *d)
{
	t_list	*new_var;

	if (ft_strncmp(d->buf, "export ", 7))
		perror("error");
	else
	{
		check_spaces(d, -1);
		if (checker(d, -1))
		{
			if (check_duplicates(d))
				return ;
			new_var = ft_lstnew(ft_strdup(d->buf));
			ft_lstadd_back(&d->env, new_var);
		}
	}
}
