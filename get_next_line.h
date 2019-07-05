/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumaseko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:21 by sumaseko          #+#    #+#             */
/*   Updated: 2019/07/04 16:32:22 by sumaseko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	32
# define MAX_FD		2147483647

# include <unistd.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
