/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:26:16 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/14 22:44:55 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_prompt(t_promp **promp)
{
	t_promp	*current;
	t_promp	*next;

	if (!promp)
		return ;
	current = *promp;
	while (current != NULL)
	{
		next = current->next;
		free (current->cmd);
		if (current->token)
			free (current->token);
		if (current->exe)
			free (current->exe);
		free (current);
		current = next;
	}
	*promp = NULL;
}
