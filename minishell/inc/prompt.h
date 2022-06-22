/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:34:18 by pnoronha          #+#    #+#             */
/*   Updated: 2022/06/22 18:38:00 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "minishell.h"

typedef struct s_prompt
{
	char	*user;
	char	*name;
	char	*pwd;
	char	*full_prompt;
}	t_prompt;

t_prompt	*pmpt(void);
void	get_prompt(void);

#endif
