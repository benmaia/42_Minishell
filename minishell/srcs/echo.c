/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/03 02:49:30 by bmiguel-         ###   ########.fr       */
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

char	*quotes(t_data *d)
{
	int	i;

	i = -1;
	while (d->buf[++i])
	{
		if (d->buf[i] == '\"')
		{
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
			i = double_quotes(d, --i);
			ft_memmove(&d->buf[i], &d->buf[i + 1], ft_strlen(d->buf) - 1);
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
	}
	return (d->buf);
}

void	ft_echo(t_data *d)
{
	char	*text;

	text = quotes(d);
	if (!ft_strncmp(text, "echo -n ", 8))
		printf("%s", ft_strchr(text, 'n') + 2);
	else
		printf("%s\n", ft_strchr(text, ' ') + 1);
}

/*int main(int argc, char **argv, char **envp)*/
/*{*/
	/*t_data	d;*/

	/*(void) argc;*/
	/*(void) argv;*/
	/*(void) envp;*/
	/*while (1)*/
	/*{*/
		/*d.buf = readline("This promp > ");*/
		/*if (!ft_strncmp(d.buf, "echo ", 5))*/
			/*ft_echo(&d);*/
		/*if (!ft_strncmp(d.buf, "exit\0", 5))*/
		/*{*/
			/*free (d.buf);*/
			/*exit (1);*/
		/*}*/
		/*free (d.buf);*/
	/*}*/
	/*return (0);*/
/*}*/
