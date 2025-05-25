/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:42:35 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:41:00 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int	true;

	true = 8;
	if (c <= '9' && c >= '0')
	{
		return (true);
	}
	if (c <= 'Z' && c >= 'A')
	{
		return (true);
	}
	else if (c <= 'z' && c >= 'a')
	{
		return (true);
	}
	else
		return (0);
	return (true);
}
