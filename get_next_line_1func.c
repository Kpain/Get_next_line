/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:13:34 by kpain             #+#    #+#             */
/*   Updated: 2016/04/05 19:34:55 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*str = NULL;
	char			buff[BUFF_SIZE + 1];
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (str)
	{
		if ((tmp = ft_strchr(str, '\n')))
		{
			*line = ft_strcsub(str, 0, '\n');
			if (*(tmp + 1))
				str = ft_strdup(++tmp);
			else
			{
				free(str);
				str = NULL;
			}
			return (1);
		}
		else
		{
			*line = str;
			str = NULL;
		}
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((tmp1 = ft_strchr(buff, '\n')))
		{
			tmp = ft_strcsub(buff, 0, '\n');
			tmp2 = ft_strjoin(*line, tmp);
			free(tmp);
			free(*line);
			*line = tmp2;
			if (*(tmp1 + 1))
				str = ft_strdup(++tmp1);
			return (1);
		}
		else
		{
			tmp1 = ft_strjoin(*line, buff);
			if (*line)
				free(*line);
			*line = tmp1;
		}
	}
	return (*line ? 1 : ret);
}
