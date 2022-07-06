/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/05 18:30:12 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/echo.h"
#include "../inc/minishell.h"

void	expand_var(t_data *d, int i, int j)
{
	char	*var;
	char	*p;
	char	*p1;
	char	*p2;
	char	*p3;

	var = ft_substr(d->buf, j, i - j);
	p = ft_substr(d->buf, 0, j);
	p1 = ft_substr(d->buf, i, ft_strlen(d->buf));
	p2 = ft_strjoin(p, getenv(var));
	p3 = ft_strjoin(p2, p1);
	free (d->buf);
	d->buf = ft_strdup(p3);
	free (p);
	free (p1);
	free (p2);
	free (p3);
	free (var);
}

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

int	double_quotes(t_data *d, int i)
{
	int	j;

	while (d->buf[++i] != '\"' && d->buf[i])
	{
		if (d->buf[i] == '$')
		{
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
			j = i;
			while (d->buf[i] != ' ' && d->buf[i] != '\"'
				&& d->buf[i] != '\'' && d->buf[i])
				i++;
			if (d->buf[i])
				expand_var(d, i, j);
			i--;
		}
	}
	return (i);
}

void	clean_extra_spaces(t_data *d, int i)
{
	while (d->buf[++i] == ' ')
	{
		ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
		i--;
	}
}

char	*quotes(t_data *d, int i)
{
	while (d->buf[++i])
	{
		if (d->buf[i] == '\"')
		{
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
			i = double_quotes(d, --i);
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
			i--;
		}
		else if (d->buf[i] == '\'')
		{
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
			while (d->buf[i] != '\'' && d->buf[i])
				i++;
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
		}
		else if (d->buf[i] == '$')
			dollar_var(d, i);
		else if (d->buf[i] == ' ')
			clean_extra_spaces(d, i);
	}
	return (d->buf);
}

void	ft_echo(t_data *d)
{
	if (!ft_strncmp(d->buf, "echo -n", 7))
	{
		if (!ft_strncmp(d->buf, "echo -n\0", 8))
			return ;
		else
			printf("%s", ft_strchr(d->buf, 'n') + 2);
	}
	else if (!ft_strncmp(d->buf, "echo ", 5)
		|| !ft_strncmp(d->buf, "echo\0", 5))
	{
		if (!ft_strncmp(d->buf, "echo\0", 5))
			printf("\n");
		else
			printf("%s\n", ft_strchr(d->buf, ' ') + 1);
	}
	else
		perror("error");
}
