/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:03:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/06/24 23:12:38 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/cd.h"

void	ft_pwd(void)
{
	char	path[1040];

	printf("%s\n", getcwd(path, sizeof(path)));
}

void	cd_path(t_cd *cd, int i)
{
	if (!ft_strncmp(cd->dest[1], "..\0", 3))
	{
		i = ft_strlen(cd->path);
		while (cd->path[--i] != '/' && i >= 0)
			cd->valid_path = ft_substr(cd->path, 0, i - 1);
	}
	else if (!ft_strncmp(cd->dest[1], "/", 1))
	{
		chdir(cd->dest[1]);
		return ;
	}
	else if (!ft_strncmp(cd->dest[1], "~", 1))
	{
		cd->tmp = ft_strchr(cd->dest[1], '/');
		cd->valid_path = ft_strjoin(getenv("HOME"), cd->tmp);
	}
	else
	{
		cd->tmp = ft_strjoin("/", cd->dest[1]);
		cd->valid_path = ft_strjoin(cd->path, cd->tmp);
		free (cd->tmp);
	}
	chdir(cd->valid_path);
	free (cd->valid_path);
}

void	cd(t_data *d)
{
	int		i;
	t_cd	cd;

	getcwd(cd.path, sizeof(cd.path));
	if (!d->buf)
		exit (0);
	cd.dest = ft_split(d->buf, ' ');
	i = 0;
	cd_path(&cd, i);
}

/*int main(int argc, char **argv, char **envp)*/
/*{*/
	/*t_data	d;*/
	/*char	l[1040];*/

	/*(void) argc;*/
	/*(void) argv;*/
	/*(void) envp;*/
	/*while (1)*/
	/*{*/
		/*d.buf = readline("This promp > ");*/
		/*if (!ft_strncmp(d.buf, "cd ", 3))*/
			/*cd(&d);*/
		/*if (!ft_strncmp(d.buf, "pwd\0", 4))*/
			/*ft_pwd();*/
		/*getcwd(l, sizeof(l));*/
		/*printf("%s\n", l);*/
		/*if (!ft_strncmp(d.buf, "exit\0", 5))*/
			/*exit (1);*/
	/*}*/
	/*return (0);*/
/*}*/
