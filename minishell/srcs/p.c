/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/14 22:42:02 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/readline.h>
#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
	t_data	d;
	int		i;

	(void) argc;
	(void) argv;
	d.env = init_env(envp);
	/*initialize_structs(&d);*/
	while (1)
	{
		i = 0;
		d.nbr_cmd = 0;
		d.buf = readline (RED"MINISHELL > "RES);
		d.p = parser_promp(&d, -1);
		parsing_tokens(&d.p);
		ft_prompprint(d.p);
		ft_prompcmd(&d);
		while (++i <= d.nbr_cmd)
		{
			if (built_in(&d))
				printf("exec\n");
		}
		free (d.buf);
		/*free (d.p->cmd);*/
		/*free_prompt(&d.p);*/
	}
	ft_free_stack(&d.env);
	/*free_prompt(&d);*/
	/*free (d.p);*/
	/*ft_free_stack(&d.env);*/
	return (0);
}
