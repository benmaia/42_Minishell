/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:55:16 by pnoronha          #+#    #+#             */
/*   Updated: 2022/06/22 19:39:03 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prompt	*pmpt(void)
{
	static t_prompt	p;

	return (&p);
}

static void	pathprompt(void)
{
	char	*aux;
	char	*aux2;

	aux = ft_strjoin(BLUE, getenv("PWD"));
	aux2 = ft_strjoin(aux, RES);
	ft_free(aux);
	aux = ft_strjoin(aux2, "$ ");
	ft_free(aux2);
	pmpt()->path = ft_strdup(aux);
	ft_free(aux);
}

static void	nameprompt(void)
{
	char	*aux;
	char	*aux2;

	aux = ft_strjoin(GREEN, getenv("USER"));
	aux2 = ft_strjoin(aux, "@");
	ft_free(aux);
	aux = ft_strjoin(aux2, getenv("NAME"));
	ft_free(aux2);
	aux2 = ft_strjoin(aux, RES);
	ft_free(aux);
	aux = ft_strjoin(aux2, ":");
	ft_free(aux2);
	pmpt()->name = ft_strdup(aux);
	ft_free(aux);
}

void	get_prompt(void)
{
	nameprompt();
	pathprompt();
	pmpt()->full_prompt = ft_strjoin(pmpt()->name, pmpt()->path);
	ft_free(pmpt()->name);
	ft_free(pmpt()->path);
}
