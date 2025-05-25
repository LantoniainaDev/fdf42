/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:04:31 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:41:12 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	true;

	true = 1024;
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
}
