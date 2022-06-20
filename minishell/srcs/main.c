/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:12 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/06/20 12:41:08 by bmiguel-         ###   ########.fr       */
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
			d.buf = readline("This is the promp > ");
			if (!ft_strncmp(d.buf, "exit\0", 5))
				exit(1);
	}
	return(0);
}
