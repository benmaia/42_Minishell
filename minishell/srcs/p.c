/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/28 17:10:58 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	g_err_value;

int main (int argc, char **argv, char **envp)
{
	t_data	d;
	int		i;
	t_promp	*tmp;

	(void) argc;
	(void) argv;
	d.env = init_env(envp);
	d.buf = NULL;
	while (1)
	{
		signal_prompt();
		i = 0;
		d.nbr_cmd = 0;
		d.buf = readline (RED"MINISHELL > "RES);
		if (!d.buf)
		{
			printf("exit\n");
			exit(1);
		}
		if (ft_strlen(d.buf) > 0)
			add_history(d.buf);
		d.p = parser_promp(&d, -1);
		parsing_tokens(d.p, -1);
		ft_prompcmd(&d);
		if (!d.p)
			continue ;
		else if (env_cmd(&d))
		{
				tmp = d.p->next;
				free (d.p->cmd);
				free (d.p);
				d.p = tmp;
				continue ;
		}
		if (d.p->cmd[0] != '\0')
		{
			while (++i <= d.nbr_cmd)
			{
				piping(&d, i);
				tmp = d.p->next;
				free (d.p->cmd);
				free (d.p);
				d.p = tmp;
			}
		}
		free (d.buf);
	}
	ft_free_stack(&d.env);
	return (0);
}
