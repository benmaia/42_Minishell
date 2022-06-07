/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:12 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/06/06 19:58:37 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

void	init_data(t_data *d)
{
	d->arg = NULL;
	/*d->buf = NULL;*/
}

int	position(t_data *d, int i)
{
	while (d->buf[++i])
	{
			if (d->buf[i] == '>' || d->buf[i] == '<'
				|| d->buf[i] == '|')
				return (i);
	}
	return (i);
}

int	nbr_words(t_data *d)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 1;

	while (d->buf[++i])
	{
			if (d->buf[nbr] == '>' || d->buf[nbr] == '<'
				|| d->buf[nbr] == '|')
				nbr++;
	}
	return (nbr);
}

int	main(int ac, char **av, char **envp)
{
	t_data	d;
	int		i;
	int		j;
	int		ii;

	(void)ac;
	(void)av;
	(void)envp;
	init_data(&d);
	i = 0;
	j = -1;
	while (1)
	{
			d.buf = readline(ORANGE1"What do u want > "RES);
			if (!ft_strncmp(d.buf, "exit\0", ft_strlen(d.buf)))
				exit(1);
			/*ft_printf("%s\n", d.buf);*/
			d.arg = (char **)malloc(sizeof(char *) * nbr_words(&d));
			ii = i;
			i = position(&d, i);
			while (d.arg[++j])
			{
					d.arg[j] = ft_substr(d.buf, ii, i);
					printf("%s\n", d.arg[j]);
			}
			/*free (d.arg[0]);*/
			/*free (d.arg);*/
	}
	/*int k = 0;*/
	/*k = position(&d, k);*/
	/*printf("%d\n", k);*/
	return (1);
}
