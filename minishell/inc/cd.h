/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:05:54 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/02 16:39:18 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

#include "../inc/minishell.h"

typedef struct s_cd {
	char	path[1040];
	char	*tmp;
	char	*valid_path;
	char	**dest;
}	t_cd;

void	cd(t_data *d);

void	ft_pwd(void);

#endif
