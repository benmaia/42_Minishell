/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:15:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/07 22:45:33 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

void	ft_prompprint(t_promp *p)
{
	t_promp	*tmp;

	tmp = p;
	while (tmp)
	{
		printf("%s\n", tmp->cmd);
		tmp = tmp->next;
	}
}

t_promp	*ft_promplast(t_promp *p)
{
	if (!p)
		return (NULL);
	while (p->next)
		p = p->next;
	return (p);
}

void	ft_prompadd(t_promp **p, t_promp *neww)
{
	t_promp	*back;

	back = *p;
	if (!back)
	{
		*p = neww;
		return ;
	}
	back = ft_promplast(*p);
	back->next = neww;
}

t_promp	*ft_prompnew(char	*cmd)
{
	t_promp	*new;

	new = (t_promp *)malloc(sizeof (t_promp));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->next = NULL;
	return (new);
}
