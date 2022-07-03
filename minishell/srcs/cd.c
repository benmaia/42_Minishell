/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:03:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/03 21:24:15 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/cd.h"

void	ft_pwd(void)
{
	char	path[1040];

	if (getcwd(path, sizeof(path)) != NULL)
		printf("%s\n", path);
	else
		exit(1); //error here
}

void	cd_relative(t_cd *cd, int i)
{
	if (!ft_strncmp(cd->dest[1], "..\0", 3))
	{
		i = ft_strlen(cd->path);
		while (cd->path[--i] != '/' && i >= 0)
		{
			if (cd->valid_path)
				free (cd->valid_path);
			cd->valid_path = ft_substr(cd->path, 0, i - 1);
		}
	}
	else
	{
		cd->tmp = ft_strjoin("/", cd->dest[1]);
		cd->valid_path = ft_strjoin(cd->path, cd->tmp);
		free (cd->tmp);
	}
}

void	cd_path(t_cd *cd, int i)
{
	if (!ft_strncmp(cd->dest[1], "/", 1))
		cd->valid_path = ft_strdup(cd->dest[1]);
	else if (!ft_strncmp(cd->dest[1], "~", 1))
	{
		if (!ft_strncmp(cd->dest[1], "~\0", 2))
			chdir(getenv("HOME"));
		else
		{
			cd->tmp = ft_strchr(cd->dest[1], '/');
			cd->valid_path = ft_strjoin(getenv("HOME"), cd->tmp);
			chdir(cd->valid_path);
		}
	}
	else
		cd_relative(cd, i);
	if (chdir(cd->valid_path) != 0)
		exit(1); //error here
	free (cd->valid_path);
}

void	cd(t_data *d)
{
	int		i;
	t_cd	cd;

	cd.valid_path = NULL;
	if (!ft_strncmp(d->buf, "cd ~\0", 5))
		chdir(getenv("HOME"));
	else if (!ft_strncmp(d->buf, "cd ", 3))
	{
		getcwd(cd.path, sizeof(cd.path));
		if (!d->buf)
			exit (0);
		cd.dest = ft_split(d->buf, ' ');
		i = 0;
		cd_path(&cd, i);
		while (cd.dest[i])
			free (cd.dest[i++]);
		free (cd.dest);
	}
	else if (!ft_strncmp(d->buf, "cd\0", 3))
		chdir(getenv("HOME"));
	else
		perror("error");
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
		/*if (!ft_strncmp(d.buf, "cd", 2))*/
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
