/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:09:48 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 15:07:44 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Recreates the CTRL-C signal*/
/*in bash prompt*/
static void	ctrl_c(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*Change the signals to prompt signals*/
void	signal_prompt(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

/*Recreates the CTRL-C signal*/
/*in bash on a block command*/
static void	ctrl_c_block(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

/*Recreates the CTRL-\ signal*/
/*in bash on a block command*/
static void	ctrl_slash_block(int sig)
{
	(void) sig;
	write(1, "Quit (core dumped)\n", 19);
	rl_on_new_line();
	rl_replace_line("", 0);
}

/*Change the signals to block command*/
void	signal_block(void)
{
	signal(SIGINT, &ctrl_c_block);
	signal(SIGQUIT, &ctrl_slash_block);
}
