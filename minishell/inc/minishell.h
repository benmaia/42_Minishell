/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/07/19 23:36:54 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
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

//Errors
# define NO_ERROR 0
# define FILE_DIR_ERR 1
# define OUT_RANGE_ERR 255
# define CTRL_C_ERR 130
# define CMD_NOT_FOUND_ERR 127

typedef struct s_args
{
	char			**cmd;
	char			*token;
	struct s_args	*next;
}	t_args;

typedef struct s_env{
	char				*var;
	struct s_env	*next;
}	t_env;

typedef struct s_promp {
	char	*cmd;
	char	*token;
	char	**exe;
	struct	s_promp	*next;
} t_promp;

typedef struct s_data {
	char	*buf;
	t_list	*env;
	t_promp	*p;
	int		nbr_cmd;
}	t_data;

/*#################### GLOBAL VAR ##################*/

extern int err_value;

/*#################### BUILT INS ##################*/

int	built_in(t_data *d);

void	cd(t_data *d);

void	ft_pwd(t_data *d);

void	ft_echo(t_data *d);

void	ft_env(t_data *d);

void	ft_unset(t_data *d);

void	ft_export(t_data *d);

/*#################### PARSER ##################*/

t_list	*init_env(char **envp);

void	parsing_tokens(t_promp **p, int i);

char	*quotes(t_data *d, int i);

char	*ft_check_var(t_list *list, char *var);

void	dollar_var(t_data *d, int i);

void	expand_var(t_data *d, int i, int j);

void	dollar_export(t_data *d, char *tmp, int i);

int	check_size(int x, int z);

t_promp	*parser_promp(t_data *d, int i);

/*#################### PROMPT ##################*/

t_promp	*ft_prompnew(char	*cmd);

void	ft_prompadd(t_promp **p, t_promp *neww);

void	ft_prompprint(t_promp *p);

void	ft_prompcmd(t_data *d);

void	initialize_structs(t_data *d);

/*#################### FREE ##################*/

void	ft_free_stack(t_list **list);

void	free_prompt(t_promp **promp);

void	ft_free(void *ptr);

#endif /* MINISHELL_H */
