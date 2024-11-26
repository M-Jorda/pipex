/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:22:29 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/26 16:22:42 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "pipex_bonus.h"

typedef struct s_arg
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	char	**env;
}	t_arg;

#endif