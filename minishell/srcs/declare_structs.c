/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:18:59 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/26 20:00:07 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	initialize_prompt(t_data *d)
{
	/*int	i;*/

	/*i = -1;*/
	d->p->cmd = NULL;
	/*while (d->p->path[++i])*/
		/*d->p->path[i] = NULL;*/
	d->p->path = NULL;
	/*i = -1;*/
	/*while (d->p->exe[++i])*/
		/*d->p->exe[i] = NULL;*/
	d->p->exe = NULL;
	/*i = -1;*/
	/*while (d->p->token[++i])*/
		/*d->p->token = NULL;*/
	d->p->token = NULL;
}

void	initialize_structs(t_data *d, char **envp)
{
	initialize_prompt(d);
	d->env = init_env(envp);
}
