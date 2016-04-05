/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:13:34 by kpain             #+#    #+#             */
/*   Updated: 2016/04/01 16:19:30 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	file_checker(int const fd, char **line, char *str[256])
{
	char	*tmp;

	if (str[fd])
	{
		if ((tmp = ft_strchr(str[fd], '\n')))
		{
			*line = ft_strcsub(str[fd], 0, '\n');
			if (*(tmp + 1))
				str[fd] = ft_strdup(++tmp);
			else
			{
				free(str[fd]);
				str[fd] = NULL;
			}
			return (1);
		}
		else
		{
			*line = str[fd];
			str[fd] = NULL;
		}
	}
	return (0);
}

static int	file_reader(int const fd, char buff[], char **line, char *str[256])
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_strchr(buff, '\n')))
	{
		tmp = ft_strcsub(buff, 0, '\n');
		tmp2 = ft_strjoin(*line, tmp);
		free(tmp);
		free(*line);
		*line = tmp2;
		if (*(tmp1 + 1))
			str[fd] = ft_strdup(++tmp1);
		return (1);
	}
	else
	{
		tmp1 = ft_strjoin(*line, buff);
		if (*line)
			free(*line);
		*line = tmp1;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*str[256] = {NULL};
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (file_checker(fd, line, str))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (file_reader(fd, buff, line, str))
			return (1);
	}
	return (*line ? 1 : ret);
}
