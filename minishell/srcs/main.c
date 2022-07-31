/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 14:30:57 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

/*Global variable to carry*/
/*the error value throw program*/
int	g_err_value;

/*Check if it's a built-in that needs*/
/*to be outside the child process and*/
/*if it is, will execute that command*/
/*while going to the next element and */
/*freeing the one he was previously*/
/*if it's not, that it will create pipes*/
/*to execute the built-in commands*/
/*that need to be in the child process*/
/*or other commands that need execve*/
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
		d->pp = malloc(sizeof(t_pipes));
		while (++i <= d->nbr_cmd)
		{
			piping(d, i);
			tmp = d->p->next;
			free (d->p->cmd);
			free (d->p);
			d->p = tmp;
		}
		free (d->pp);
	}
}

/*First if the promp have to valid char*/
/*it will store in the history, and then*/
/*will make a parsing, dividing cmds per elements*/
/*on a list, and after, it will parse the*/
/*command itself for a more general parsing*/
void	parser_minishell(t_data *d)
{
	if (ft_strlen(d->buf) > 0)
		add_history(d->buf);
	d->p = parser_promp(d, 0);
	ft_prompcmd(d);
}

/*Free a var and set's it to NULL*/
void	myfree(void **ptr)
{
	if (*ptr)
		free (*ptr);
	*ptr = NULL;
}

/*The main function will init the env variables*/
/*and store them in a list. Inside the program*/
/*it's changing the signals to prompt bash signals*/
/*sets the cmd_nbrs to 0 and stores the promp in */
/*d.buf, after that it passes for a general parsing*/
/*checks if there is any command and if there is*/
/*then executes it and frees de d.buf, so readline*/
/*writes the promp in d.buf again with no leaks*/
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
		parser_minishell(&d);
		if (!d.p)
			continue ;
		exec_cmds(&d, 0);
		myfree((void *)&d.buf);
	}
	ft_free_stack(&d.env);
	return (0);
}
