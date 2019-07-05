/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumaseko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:41:52 by sumaseko          #+#    #+#             */
/*   Updated: 2019/07/05 12:36:27 by sumaseko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_substring(int fd, char *file[], char **line, int el)
{
	unsigned int	l_len;
	size_t			f_len;
	int				len;
	char			*sbstr;

	l_len = (unsigned int)ft_strlen(*line);
	f_len = (size_t)ft_strlen(file[fd]);
	len = (int)ft_strlen(*line);
	sbstr = ft_strsub(file[fd], l_len + el, f_len - len + el);
	return (sbstr);
}

int		get_next_line(const int fd, char **line)
{
	static char *file[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			ret;
	int			el;

	if (fd < 0 || (!file[fd] && !(file[fd] = ft_strnew(1))) || !line)
		return (-1);
	while ((!ft_strchr(file[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		temp = file[fd];
		file[fd] = ft_strjoin(file[fd], buf);
		ft_strdel(&temp);
	}
	if (ret == -1 || !*(temp = file[fd]))
		return (ret == -1 ? -1 : 0);
	if ((el = (ft_strchr(file[fd], '\n') > 0)))
		*line = ft_strsub(file[fd], 0, ft_strchr(file[fd], '\n') - file[fd]);
	else
		*line = ft_strdup(file[fd]);
	file[fd] = (char*)ft_substring(fd, file, line, el);
	ft_strdel(&temp);
	return (!(!file[fd] && !ft_strlen(*line)));
}
