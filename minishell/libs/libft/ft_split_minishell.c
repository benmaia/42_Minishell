/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:58:27 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/05/19 17:13:22 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrquotes(char *s, int i)
{
		if (s[i] == 39)
		{
				++i;
				while (s[i] != 39)
							i++;
		}
		else if (s[i] == 34)
		{
				++i;
				while (s[i] != 34)
							i++;
		}
		return (i);
}


int	nbwords(char *s)
{
		int i;
		int nb;
		int flag;

		i = -1;
		flag = 0;
		nb = 0;
		while (s[++i])
		{
				i = nbrquotes(s, i);
				if (s[i] != 32 && flag == 0)
				{
						flag = 1;
						nb++;
				}
				else if (s[i] == 32)
						flag = 0;
		}
		return (nb);
}

int main()
{
		char *s;
		s = "ola ola 'eu ola ola' 'ola ola' ol amigo ";
		/*s = "ola ola ola 'ola ola ola' ola 'ola ola ola ola' ola";*/
		int o;

		o = nbwords(s);
		printf("%d", o);
		return (0);
}
