/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/07 16:40:03 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/readline.h>
#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
	t_data d;

	(void) argc;
	(void) argv;
	d.env = init_env(envp);
	while (1)
	{
		d.buf = readline (RED"MINISHELL > "RES);
		if (!ft_strncmp(d.buf, "export", 6))
			ft_export(&d);
		quotes(&d, -1);
		if (!ft_strncmp(d.buf, "unset", 5))
			ft_unset(&d);
		if (!ft_strncmp(d.buf, "pwd", 3))
			ft_pwd();
		if (!ft_strncmp(d.buf, "env", 3))
			ft_env(&d);
		if (!ft_strncmp(d.buf, "cd", 2))
			cd(&d);
		if (!ft_strncmp(d.buf, "echo", 4))
			ft_echo(&d);
		if (!ft_strncmp(d.buf, "exit\0", 5))
		{
			free (d.buf);
			ft_free_stack(&d.env);
			exit (1);
		}
		free (d.buf);
	}
	/*ft_free_stack(&d.env);*/
	/*ft_free_stack(&d.env);*/
	return (0);
}
