/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:55:16 by pnoronha          #+#    #+#             */
/*   Updated: 2022/06/22 18:40:19 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prompt	*pmpt(void)
{
	static t_prompt	p;

	return (&p);
}

void	join_prompt()
{
	char	*aux;
	char	*aux2;

	aux = ft_strjoin(pmpt()->user, "@");
	aux2 = ft_strjoin(aux, pmpt()->name);
	ft_free(aux);
	aux = ft_strjoin(aux2, ":");
	ft_free(aux2);
	aux2 = ft_strjoin(aux, pmpt()->pwd);
	ft_free(aux);
	aux = ft_strjoin(aux2, "$ ");
	ft_free(aux2);
	pmpt()->full_prompt = malloc(sizeof(char) * ft_strlen(aux) + 1);
	ft_strlcpy(pmpt()->full_prompt, aux, ft_strlen(aux) + 1);
	ft_free(aux);
}

void	get_prompt(void)
{
	pmpt()->user = getenv("USER");
	pmpt()->name = getenv("NAME");
	pmpt()->pwd = getenv("PWD");
	join_prompt();
}
