/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:09:33 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/05/26 23:15:19 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*back;

	back = *lst;
	if (!back)
	{
		*lst = n;
		return ;
	}
	back = ft_lstlast(*lst);
	back->next = n;
}
