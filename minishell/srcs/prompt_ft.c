/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:15:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/14 18:22:53 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

void	ft_prompcmd(t_data *d)
{
	d->nbr_cmd = 1;
	if (!d)
		return ;
	while (d->p->next)
	{
		d->nbr_cmd++;
		d->p = d->p->next;
	}
	return ;
}

/*It prints all the elements*/
/*in the t_prompt list*/
void	ft_prompprint(t_promp *p)
{
	t_promp	*tmp;

	tmp = p;
	while (tmp)
		tmp = tmp->next;
}

/*Returns the pointer to*/
/*the last element of the*/
/*of the t_promp list*/
t_promp	*ft_promplast(t_promp *p)
{
	if (!p)
		return (NULL);
	while (p->next)
		p = p->next;
	return (p);
}

/*Adds a new element in the end*/
/*of the t_promp list*/
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

/*Creates an element of type t_promp*/
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
