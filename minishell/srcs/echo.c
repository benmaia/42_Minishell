/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/26 23:55:26 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/echo.h"
#include "../inc/minishell.h"

void	echo_line(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo\0", 5))
	{
		printf("\n");
		exit (1);
	}
	else
	{
		printf("%s\n", ft_strchr(d->p->cmd, ' ') + 1);
		exit (1);
	}
}

void	echo_noline(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo -n\0", 8))
		exit (1);
		/*return ;*/
	else
	{
		printf("%s", ft_strchr(d->p->cmd, 'n') + 2);
		exit (1);
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
		perror("error");
		exit(1);
	}
}
