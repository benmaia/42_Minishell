/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:12 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/06/22 19:42:07 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/readline.h>
#include <stdlib.h>

int main ()
{
	t_data d;

	while (1)
	{
		get_prompt();
		d.buf = readline(pmpt()->full_prompt);
		ft_free(pmpt()->full_prompt);
		if (!ft_strncmp(d.buf, "exit\0", 5))
			exit(1);
	}
	return(0);
}
