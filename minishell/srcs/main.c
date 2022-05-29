/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:12 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/05/29 19:07:41 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_data(t_data *d)
{
	d->arg = NULL;
	d->buf = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_data	d;
	int		i;

	(void)ac;
	(void)av;
	(void)envp;
	init_data(&d);
	while (1)
	{
		d.buf = readline(ORANGE1"What do u want > "RES);
		if (!ft_strncmp(d.buf, "exit\0", ft_strlen(d.buf)))
			exit(1);
		d.arg = ft_split(d.buf, ' ');
		i = -1;
		while (d.arg[++i])
			ft_printf("%s\n", d.arg[i]);
	}
	return (0);
}
