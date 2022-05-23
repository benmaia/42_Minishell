/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:58:27 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/05/23 16:55:51 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrquotes(const char *s, int i)
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


int	nbwords(const char *s, char c)
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
				else if (s[i] == c)
						flag = 0;
		}
		return (nb);
}

static char	*word_dup(const char *str, int start, int finish)
{
		char	*word;
		int		i;

		i = 0;
		word = malloc(finish - start + 1);
		while(start < finish)
				word[i++] = str[start++];
		word[i] = '\0';
		return (word);
}

char	**ft_split_minishell(char const *s, char c)
{
		size_t	i;
		size_t	j;
		int		index;
		char	**split;

		split = (char **)malloc(sizeof(char *) * (nbwords(s, c) + 1));
		if (!s || !split)
				return (NULL);
		i = -1;
		j = 0;
		index = -1;
		while (++i < ft_strlen(s))
		{
				if (s[i] != 39 && index < 0)
					index = i;
				else if ((s[i] == 39) || (i == ft_strlen(s) && index >= 0))
				if ((s[i] != c && index < 0)
					index = i;
				else if ((s[i] == c) || (i == ft_strlen(s) && index >= 0))
				{
					split[j++] = word_dup(s, index, i);
					index = -1;
				}
				/*if (s[i] != c && index < 0)*/
							/*index = i;*/
				/*else if ((s[i] == c) || (i == ft_strlen(s) && index >= 0))*/
							/*{*/
									/*split[j++] = word_dup(s, index, i);*/
									/*index =-1;*/
							/*}*/
		}
		split[j] = 0;
		return (split);
}

/*int main()*/
/*{*/
		/*char *s;*/
		/*s = "ola ola 'eu ola ola' 'ola ola' ol amigo ";*/
		/*s = "ola ola ola 'ola ola ola' ola 'ola ola ola ola' ola";*/
		/*int o;*/
		/*char **ola;*/

		/*o = nbwords(s, ' ');*/
		/*printf("%d", o);*/
		/*int i = -1;*/
		/*ola =ft_split_minishell(s, ' ');*/
		/*while (ola[++i])*/
					/*printf("%s\n", ola[i]);*/
		/*return (0);*/
/*}*/
