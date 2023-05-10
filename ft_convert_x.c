/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:57:32 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/27 21:57:32 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_x(int c, unsigned long long num, t_flags *flags)
{
	int	lenarg;

	lenarg = ft_baselen(num, 16);
	if (flags->before == '#' && num > 0)
		lenarg += 2;
	if (flags->point != -1)
	{
		flags->blank = ' ';
		if (num > 0 && flags->point < lenarg)
			flags->point = lenarg;
	}
	else if (flags->point == -1)
		flags->point = lenarg;
	return (ft_printf_x(c, num, flags));
}

int	ft_printf_x(int c, unsigned long long num, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->left)
		len += ft_printf_arg_x(c, num, flags);
	len += ft_printf_flags_x(flags);
	if (!flags->left)
		len += ft_printf_arg_x(c, num, flags);
	return (len);
}

int	ft_printf_flags_x(t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->space && flags->width == 0)
		len += ft_printf_char(' ');
	while (len < flags->width - flags->point)
		len += ft_printf_char(flags->blank);
	return (len);
}

int	ft_printf_arg_x(int c, unsigned long long num, t_flags *flags)
{
	int	len;
	int	i;

	len = 0;
	if (flags->before == '#' && num > 0)
		len += ft_printf_char('0') + ft_printf_char(c);
	i = len + ft_baselen(num, 16);
	while (i < flags->point)
	{
		len += ft_printf_char('0');
		i++;
	}
	if (num > 0 || flags->point > 0)
		len += ft_printf_base16(num, c, 0);
	return (len);
}

int	ft_printf_base16(unsigned long long n, int c, int i)
{
	if (n == 0)
	{
		if (i == 0)
			return (ft_printf_char('0'));
		return (i);
	}
	i = ft_printf_base16(n / 16, c, i + 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
	return (i);
}
