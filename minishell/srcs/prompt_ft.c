/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:15:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/31 15:05:53 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Stores the command in the cmd*/
/*variable to send it to parser*/
/*and execve*/
void	ft_prompcmd(t_data *d)
{
	t_promp	*tmp;

	d->nbr_cmd = 1;
	if (!d || !d->p)
		return ;
	tmp = d->p;
	while (tmp->next)
	{
		d->nbr_cmd++;
		tmp = tmp->next;
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
	t_promp	**tmp;

	tmp = p;
	back = *tmp;
	if (!back)
	{
		*p = neww;
		return ;
	}
	back = ft_promplast(*tmp);
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
