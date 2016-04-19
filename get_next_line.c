/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 16:54:36 by kpain             #+#    #+#             */
/*   Updated: 2016/04/08 16:35:51 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_fd(t_file **file, int fd)
{
	if (*file)
	{
		while ((*file)->back)
			*file = (*file)->back;
		while ((*file)->fd != fd && (*file)->next)
			*file = (*file)->next;
		if ((*file)->fd == fd)
			return (1);
		if (!((*file)->next = (t_file*)malloc(sizeof(t_file))))
			return (0);
		(*file)->next->back = *file;
		*file = (*file)->next;
	}
	else
	{
		if (!(*file = (t_file*)malloc(sizeof(t_file))))
			return (0);
		(*file)->back = NULL;
	}
	(*file)->next = NULL;
	(*file)->fd = fd;
	(*file)->str = NULL;
	return (1);
}

static int	get_prev_read(t_file *file, char **line)
{
	char	*tmp;
	char	*tmp2;

	if (!file->str)
		return (0);
	if ((tmp2 = ft_strchr(file->str, '\n')))
	{
		*line = ft_strsub(file->str, 0, (int)(tmp2 - file->str));
		if (ft_strlen(++tmp2))
			tmp = ft_strdup(tmp2);
		else
			tmp = NULL;
		free(file->str);
		file->str = tmp;
	}
	else if (ft_strlen(file->str))
	{
		*line = file->str;
		file->str = NULL;
	}
	return (tmp2 ? 1 : 0);
}

static int	read_line(char *buf, t_file *file, char **line)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if ((tmp2 = ft_strchr(buf, '\n')))
	{
		tmp3 = ft_strsub(buf, 0, (int)(tmp2 - buf));
		tmp = ft_strjoin(*line, tmp3);
		free(tmp3);
		if (ft_strlen(++tmp2))
			file->str = ft_strdup(tmp2);
	}
	else
		tmp = ft_strjoin(*line, buf);
	if (*line)
		free(*line);
	*line = tmp;
	if (tmp2)
		return (1);
	return (0);
}

static void	del_file(t_file **file)
{
	t_file	*tmp;

	tmp = *file;
	if (tmp->str)
		free(tmp->str);
	if (!(tmp->next) && !(tmp->back))
		tmp = NULL;
	else
	{
		if (tmp->back)
		{
			tmp->back->next = (tmp->next ? tmp->next : NULL);
			tmp = tmp->back;
		}
		if (tmp->next)
		{
			tmp->next->back = (tmp->back ? tmp->back : NULL);
			if (tmp == *file)
				tmp = tmp->next;
		}
	}
	free(*file);
	*file = tmp;
}

int			get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	int				ret;
	char			*buf;

	if (!line || fd < 0
		|| !(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*line = NULL;
	if (!check_fd(&file, fd))
		return (-1);
	if (get_prev_read(file, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (read_line(buf, file, line))
			break ;
	}
	if (ret == 0)
		del_file(&file);
	free(buf);
	return (ret > 0 || *line ? 1 : ret);
}
