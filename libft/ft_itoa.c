/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:04:42 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:41:27 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_power(int n)
{
	int	n2;
	int	d;

	d = 0;
	n2 = n;
	while (n2 >= 10)
	{
		n2 /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	d = ft_count_power(n);
	s = ft_calloc(d + 2 + neg, sizeof(char));
	if (!s)
		return (s);
	while (d >= 0)
	{
		s[d + neg] = (char)(n % 10 + '0');
		n /= 10;
		d--;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
