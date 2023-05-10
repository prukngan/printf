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

#include "ft_printf.h"

int	ft_convert(char const c, t_flags *flags, va_list *lst)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_convert_c(va_arg(*lst, int), flags);
	else if (c == 's')
		len += ft_convert_s(va_arg(*lst, char *), flags);
	else if (c == 'p')
		len += ft_convert_p(va_arg(*lst, unsigned long long), flags);
	else if (c == 'x' || c == 'X')
		len += ft_convert_x(c, va_arg(*lst, unsigned int), flags);
	else if (c == 'u')
		len += ft_convert_d(va_arg(*lst, unsigned int), flags);
	else if (c == 'd' || c == 'i')
		len += ft_convert_d(va_arg(*lst, int), flags);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	t_flags	flags;
	int		len;

	va_start(lst, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s = ft_flags(s + 1, &flags);
			if (*s == '%')
				len += ft_printf_char('%');
			else
				len += ft_convert(*s, &flags, &lst);
		}
		else
			len += write(1, s, 1);
		s++;
	}
	va_end(lst);
	return (len);
}
