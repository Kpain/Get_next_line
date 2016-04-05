/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:41:13 by kpain             #+#    #+#             */
/*   Updated: 2015/12/09 13:16:24 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = ft_memalloc(len);
	ft_memcpy(tmp, src, len);
	while (i < len)
	{
		*(char *)(dst + i) = tmp[i];
		i++;
	}
	return (dst);
}
