/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/06/22 18:42:36 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "prompt.h"
# include <readline/readline.h>
# include <readline/history.h>

// Colors
# define BLACK "\e[1;30m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define PURPLE "\e[1;35m"
# define CYAN "\e[1;36m"
# define WHITE "\e[1;37m"
# define RES "\e[0m"
# define ORANGE1 "\033[38;5;214m"
# define ORANGE2 "\033[38;5;202m"

typedef struct s_args
{
	char			**cmd;
	char			*token;
}	t_args;
typedef struct s_data {
	char	**arg;
	char	*buf;
}	t_data;

void	ft_free(void *ptr);

#endif
