/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:18:59 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/14 22:28:24 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	initialize_structs(t_data *d)
{
	d->p->cmd = NULL;
	d->p->exe = NULL;
	d->p->token = NULL;
}
