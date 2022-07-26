/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:03:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/26 01:36:16 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/cd.h"
#include <readline/tilde.h>

/*Uses the function getcwd to get */
/*the current path and print it*/
void	ft_pwd(t_data *d)
{
	char	path[1040];

	if (!ft_strncmp(d->p->cmd, "pwd ", 4)
			|| !ft_strncmp(d->p->cmd, " pwd ", 5)
			|| !ft_strncmp(d->p->cmd, "pwd\0", 5))
		{
		if (getcwd(path, sizeof(path)) != NULL)
		{
			printf("%s\n", path);
			g_err_value = 0;
		}
		else
		{
			g_err_value = CMD_NOT_FOUND_ERR;
			perror("error");
		}
	}
	else
	{
		perror("error");
		g_err_value = CMD_NOT_FOUND_ERR;
	}
}

/*It executes the relative command, for that*/
/*it will check the path given, and concatenate*/
/*with the current dir, so it gets an absolute path*/
/*so that in cd_path function the ch_dir can be called*/
/*and change to the right path*/
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

/*Will check if the command path is absolute*/
/*or relative, if it's an absolute command, it*/
/*will just get the full command as a path, if it's*/
/*an relative command, it will call the cd_relative*/
/*to do the right parsing. After it check if it's*/
/*an absolute or relative path it will execute the*/
/*ch_dir function to change paths*/
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
		}
	}
	else
		cd_relative(cd, i);
	if (chdir(cd->valid_path) != 0)
	{
		g_err_value = FILE_DIR_ERR;
		perror("cd");
	}
	free (cd->valid_path);
}

void	cd_relative_path(t_data *d, t_cd *cd)
{
	int	i;

	getcwd(cd->path, sizeof(cd->path));
	if (!d->p->cmd)
		exit (0);
	cd->dest = ft_split(d->p->cmd, ' ');
	i = 0;
	cd_path(cd, i);
	while (cd->dest[i])
		free (cd->dest[i++]);
	free (cd->dest);
}

/*Replicates the cd command on bash*/
/*If the cd have a written path, it will*/
/*get the current dir, and check if the */
/*command given has a absolute or relative*/
/*path with the cd_path function*/
void	cd(t_data *d)
{
	t_cd	cd;

	cd.valid_path = NULL;
	if (!ft_strncmp(d->p->cmd, "cd ~\0", 5))
		chdir(getenv("HOME"));
	else if (!ft_strncmp(d->p->cmd, "cd ", 3))
		cd_relative_path(d, &cd);
	else if (!ft_strncmp(d->p->cmd, "cd\0", 3))
		chdir(getenv("HOME"));
	else
	{
		g_err_value = FILE_DIR_ERR;
		perror("cd");
	}
}
