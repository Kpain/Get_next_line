/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:00:38 by kpain             #+#    #+#             */
/*   Updated: 2016/01/08 12:36:43 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 18

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
	struct s_file	*back;
}				t_file;

int				get_next_line(int const fd, char **line);

#endif
