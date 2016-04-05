/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:09:38 by kpain             #+#    #+#             */
/*   Updated: 2015/12/09 13:00:59 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizeint(int n)
{
	int result;

	result = 1;
	while (n >= 10)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static int		is_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char			*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*result;

	neg = is_neg(n);
	if (neg)
		n = -n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = sizeint(n);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1 + neg))))
		return (NULL);
	result[size + neg] = '\0';
	size--;
	while (size >= 0)
	{
		result[size + neg] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
