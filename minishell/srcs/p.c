/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/25 18:12:49 by bmiguel-         ###   ########.fr       */
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
	/*t_data	*tmp;*/

	(void) argc;
	(void) argv;
	d.env = init_env(envp);
	initialize_structs(&d);
			t_promp *o;
	d.buf = NULL;
	while (1)
	{
		i = 0;
		d.nbr_cmd = 0;
		d.buf = readline ("MINISHELL > ");
		printf("buf %s\n", d.buf);
		if (!d.buf)
		{
			/*printf("here\n");*/
			exit(1);
		}
		if (ft_strlen(d.buf) > 0)
			add_history(d.buf);
		d.p = parser_promp(&d, -1);
		parsing_tokens(d.p, -1);
		/*ft_prompprint(d.p);*/
		/*tmp = &d;*/
		ft_prompcmd(&d);
		while (++i <= d.nbr_cmd)
		{
			piping(&d, i);
			/*if (built_in(&d))*/
				/*cmds_exec(&d);*/
			/*d.p = d.p->next;*/
			o = d.p->next;
			free (d.p->cmd);
			free (d.p);
			d.p = o;
			/*tmp->p = tmp->p->next;*/
		}
		free (d.buf);
		/*free_prompt(&d.p);*/
	}
	ft_free_stack(&d.env);
	return (0);
}
