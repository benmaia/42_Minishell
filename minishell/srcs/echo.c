/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/02 16:52:48 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/echo.h"
#include "../inc/minishell.h"
#include <stdio.h>

void	ft_echo(t_data *d)
{
	if (!ft_strncmp(d->buf, "echo -n ", 8))
		printf("%s", ft_strchr(d->buf, 'n') + 2);
	else
		printf("%s\n", ft_strchr(d->buf, ' ') + 1);
}

int main(int argc, char **argv, char **envp)
{
	t_data	d;

	(void) argc;
	(void) argv;
	(void) envp;
	while (1)
	{
		d.buf = readline("This promp > ");
		if (!ft_strncmp(d.buf, "echo ", 5))
			ft_echo(&d);
		if (!ft_strncmp(d.buf, "exit\0", 5))
			exit (1);
	}
	return (0);
}
