/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:17:57 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/25 21:17:57 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

int	ft_baselen(unsigned long long num, unsigned int base)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

int ft_llonglen(long long num)
{
	if (num < 0)
		return (1 + ft_baselen(-num, 10));
	return (ft_baselen(num, 10));
}