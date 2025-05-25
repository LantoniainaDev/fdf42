/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:50:35 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:40:41 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_parse(const char *str)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

static int	is_space(const char c)
{
	int	space;

	space = c == ' ' || c == '\f' || c == '\n' || c == '\r';
	space = space || c == '\t' || c == '\v';
	return (space);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	nbr = ft_parse(nptr + i) * sign;
	return (nbr);
}
