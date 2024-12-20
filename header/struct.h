/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:49:48 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/26 16:25:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_arg
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	char	**env;
}	t_arg;

#endif