/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/11 16:19:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/echo.h"
#include "../inc/minishell.h"

/*Replicates the command echo in bash, it*/
/*checks if there is a -n flag or not, and*/
/*act accordingly, and prints the string that */
/*was recieve by the prompt*/
void	ft_echo(t_data *d)
{
	if (!ft_strncmp(d->p->cmd, "echo -n", 7))
	{
		if (!ft_strncmp(d->p->cmd, "echo -n\0", 8))
			return ;
		else
			printf("%s", ft_strchr(d->p->cmd, 'n') + 2);
	}
	else if (!ft_strncmp(d->p->cmd, "echo ", 5)
		|| !ft_strncmp(d->p->cmd, "echo\0", 5))
	{
		if (!ft_strncmp(d->p->cmd, "echo\0", 5))
			printf("\n");
		else
			printf("%s\n", ft_strchr(d->p->cmd, ' ') + 1);
	}
	else
		perror("error");
}
