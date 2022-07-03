/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/03 12:31:30 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

/*void	ft_env(t_data *d)*/
/*{*/
	/*int	i;*/

	/*i = 0;*/
	/*if (!ft_strncmp(d->buf, "env\0", 4))*/
		/*while (d->env[i])*/
			/*printf("%s\n", d->env[i++]);*/
/*}*/

t_env	*ft_lst_last(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_env	*ft_lst_new(void *content)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof (t_env));
	if (!new)
		return (NULL);
	new->var = content;
	new->next = NULL;
	return (new);
}

void	ft_lst_add_back(t_env **env, t_env *new)
{
	t_env	*back;

	back = *env;
	if (!back)
	{
		*env = new;
		return ;
	}
	back = ft_lst_last(*env);
	back->next = new;
}

int main (int argc, char **argv, char **envp)
{
	t_data d;
	
	(void) argc;
	(void) argv;
	int i = -1;
	d.env = malloc(sizeof(t_env));
	while (envp[++i])
	{
		ft_lst_add_back(&d.env, ft_lst_new(envp[i]));
		printf("%s\n", d.env->var);
		d.env = d.env->next;
	}
	/*d.env[++i] = NULL;*/
	/*while (1)*/
	/*{*/
		/*d.buf = readline("This promp > ");*/
		/*quotes(&d);*/
		/*printf("%s\n", d.buf);*/
		/*if (!ft_strncmp(d.buf, "env", 3))*/
			/*ft_env(&d);*/
		/*if (!ft_strncmp(d.buf, "echo ", 5))*/
			/*ft_echo(&d);*/
		/*if (!ft_strncmp(d.buf, "exit\0", 5))*/
		/*{*/
			/*free (d.buf);*/
			/*exit (1);*/
		/*}*/
		/*free (d.buf);*/
	/*}*/
	return (0);
}
