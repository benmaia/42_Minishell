/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/30 22:33:32 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_line(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo\0", 5))
	{
		printf("\n");
		exit (0);
	}
	else
	{
		printf("%s\n", ft_strchr(d->p->cmd, ' ') + 1);
		exit (0);
	}
}

void	echo_noline(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo -n\0", 8))
		exit (0);
	else
	{
		printf("%s", ft_strchr(d->p->cmd, 'n') + 2);
		exit (0);
	}
}

/*Replicates the command echo in bash, it*/
/*checks if there is a -n flag or not, and*/
/*act accordingly, and prints the string that */
/*was recieve by the prompt*/
void	ft_echo(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo -n", 7))
	{
		echo_noline(d);
		g_err_value = NO_ERROR;
	}
	else if (!ft_strncmp(d->p->cmd, "echo ", 5)
		|| !ft_strncmp(d->p->cmd, "echo\0", 5))
	{
		echo_line(d);
		g_err_value = NO_ERROR;
		exit(0);
	}
	else
	{
		g_err_value = CMD_NOT_FOUND_ERR;
		ft_putstr_fd("error: cmd not found\n", 2);
		exit(127);
	}
}
