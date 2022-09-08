/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:50 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/09/06 17:18:12 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <ctype.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

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

typedef struct s_cd {
	char	path[1040];
	char	*tmp;
	char	*valid_path;
	char	**dest;
}	t_cd;

typedef struct s_pipes {
	int		pipes[2];
	pid_t	pid;
	int		pipe_fd;
}	t_pipes;

typedef struct s_promp {
	char			*cmd;
	char			*pre_token;
	char			**token;
	char			**exe;
	char			**path;
	char			*cmd_path;
	char			**envp;
	struct s_promp	*next;
}	t_promp;

typedef struct s_data {
	char	*buf;
	t_list	*env;
	t_promp	*p;
	int		nbr_cmd;
	t_pipes	*pp;
}	t_data;

/*#################### GLOBAL VAR ##################*/

extern int	g_err_value;

/*#################### BUILT INS ##################*/

void	cd(t_data *d);

int		env_cmd(t_data *d);

int		built_in(t_data *d);

void	cd(t_data *d);

void	ft_pwd(t_data *d);

void	ft_echo(t_data *d);

void	ft_env(t_data *d);

void	ft_unset(t_data *d);

void	ft_export(t_data *d);

int		export_check_duplicates(t_data *d);

/*#################### PARSER ##################*/

t_list	*init_env(char **envp);

void	parsing_tokens(t_promp *p, int i);

int		tokenizer(char c);

char	*quotes(t_data *d, int i);

char	*ft_check_var(t_list *list, char *var);

void	dollar_var(t_data *d, int i);

void	expand_var(t_data *d, int i, int j);

void	dollar_export(t_data *d, char *tmp, int i);

int		check_size(int x, int z);

t_promp	*parser_promp(t_data *d, int i);

/*#################### PIPES ##################*/

void	piping(t_data *d, int x);

/*#################### PROMPT ##################*/

t_promp	*ft_prompnew(char	*cmd);

void	ft_prompadd(t_promp **p, t_promp *neww);

void	ft_prompprint(t_promp *p);

void	ft_prompcmd(t_data *d);

void	initialize_structs(t_data *d, char **envp);

/*#################### FREE ##################*/

void	ft_free_stack(t_list **list);

void	myfree(void **ptr);

/*#################### COMMANDS ##################*/

void	find_path(t_data *d);

void	cmds_exec(t_data *d, int i);

void	relative_cmd(t_data *d);

int		absolute_cmd(t_data *d);

/*#################### SIGNALS ##################*/

void	signal_prompt(void);

void	signal_block(void);

/*#################### EXIT ##################*/

void	ft_exit(t_data *d);

#endif /* MINISHELL_H */
