/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/20 22:15:07 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/echo.h"
#include "../inc/minishell.h"

void	echo_line(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo\0", 5))
		printf("\n");
	else
		printf("%s\n", ft_strchr(d->p->cmd, ' ') + 1);
}

void	echo_noline(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo -n\0", 8))
		return ;
	else
		printf("%s", ft_strchr(d->p->cmd, 'n') + 2);
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
		err_value = NO_ERROR;
	}
	else if (!ft_strncmp(d->p->cmd, "echo ", 5)
		|| !ft_strncmp(d->p->cmd, "echo\0", 5))
	{
		echo_line(d);
		err_value = NO_ERROR;
	}
	else
	{
		err_value = CMD_NOT_FOUND_ERR;
		perror("error");
	}
}
