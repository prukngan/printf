/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:32:29 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/16 22:32:29 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*ft_utoa(unsigned int n)
{
	char	*str;
	long	num;
	size_t	len;

	num = n;
	len = intlen(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (num == 0)
		*str = '0';
	else if (num < 0)
	{
		num = -num;
		*str = '-';
	}
	while (num)
	{
		*(str + len--) = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}

void	ft_printf_base10(long n, int c)
{
	char *s;

	if (c == 'd' || c == 'i')
		s = ft_itoa(n);
	else if (c == 'u')
		s = ft_utoa(n);
	len += write(1, &s, ft_strlen(s));
	free(s);
}