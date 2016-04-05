/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:13:43 by kpain             #+#    #+#             */
/*   Updated: 2016/04/01 17:37:10 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 13

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int				get_next_line(int const fd, char **line);

#endif
