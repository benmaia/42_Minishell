/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/30 21:23:52 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	g_err_value;

void	exec_cmds(t_data *d, int i)
{
	t_promp	*tmp;

	if (env_cmd(d))
	{
		tmp = d->p->next;
		free (d->p->cmd);
		free (d->p);
		d->p = tmp;
	}
	else if (d->p->cmd[0] != '\0')
	{
		while (++i <= d->nbr_cmd)
		{
			piping(d, i);
			tmp = d->p->next;
			free (d->p->cmd);
			free (d->p);
			d->p = tmp;
		}
	}
}

void	parser_minishell(t_data *d)
{
	d->p = parser_promp(d, 0);
	ft_prompcmd(d);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;

	(void) argc;
	(void) argv;
	d.env = init_env(envp);
	while (1)
	{
		signal_prompt();
		d.nbr_cmd = 0;
		d.buf = readline (RED"MINISHELL > "RES);
		if (!d.buf)
		{
			printf("exit\n");
			exit(1);
		}
		if (ft_strlen(d.buf) > 0)
			add_history(d.buf);
		parser_minishell(&d);
		if (!d.p)
			continue ;
		exec_cmds(&d, 0);
		free (d.buf);
	}
	ft_free_stack(&d.env);
	return (0);
}
