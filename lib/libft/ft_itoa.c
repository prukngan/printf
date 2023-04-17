/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:59:21 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/11 14:39:43 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	intlen(long num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
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

// int main()
// {
//   char  *str = ft_itoa(0);

//   printf("str = %s\n", str);
// }
