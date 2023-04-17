/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:53:48 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/16 20:53:48 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdarg.h>

void	ft_check_type(int const c, va_list *lst)
{
	if (c == 's')
		ft_printf_str(va_arg(*lst, char *));
	else if (c == 'p' || c == 'x' || c == 'X')
		ft_printf_base16(va_arg(*lst, unsigned long long), c);
	else if (c == 'd' || c == 'i')
		ft_printf_base10(va_arg(*lst, int), c);
	else if (c == 'u')
		ft_printf_base10(va_arg(*lst, unsigned int), 'u');
	else
		write(1, &c, 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;

	if (s == NULL)
		return (0);
	va_start(lst, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
			ft_check_type(*(s + 1), &lst);
	}
	va_end(lst);
	return (len);
}
