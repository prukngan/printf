/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:45:51 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/27 21:45:51 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_d(long num, t_flags *flags)
{
	int	lenarg;

	lenarg = ft_llonglen(num);
	if (flags->point != -1)
	{
		flags->blank = ' ';
		if (num < 0)
			flags->point++;
		else if (num == 0)
			lenarg = 0;
	}
	else if (flags->point == -1)
	{
		flags->point = 0;
		if (num < 0 && flags->blank == '0')
			flags->point = flags->width;
	}
	if (flags->point < lenarg)
		flags->point = lenarg;
	return (ft_printf_d(num, lenarg, flags));
}

int	ft_printf_d(long num, int lenarg, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->left)
		len += ft_printf_arg_d(num, lenarg, flags) + ft_printf_flags_d(flags);
	else if (!flags->left)
		len += ft_printf_flags_d(flags) + ft_printf_arg_d(num, lenarg, flags);
	return (len);
}

int	ft_printf_flags_d(t_flags *flags)
{
	int	len;

	len = 0;
	while (len < flags->width - flags->point)
		len += ft_printf_char(flags->blank);
	return (len);
}

int	ft_printf_arg_d(long num, int lenarg, t_flags *flags)
{
	int	len;
	int	i;

	len = 0;
	if (num >= 0)
	{
		if (flags->space)
			len += ft_printf_char(' ');
		if (flags->before == '+')
			len += ft_printf_char('+');
	}
	else if (num < 0)
	{
		len += ft_printf_char('-');
		num *= -1;
	}
	i = lenarg;
	while (i < flags->point)
	{
		len += ft_printf_char('0');
		i++;
	}
	if (lenarg != 0)
		len += ft_printf_base10(num, 0);
	return (len);
}

int	ft_printf_base10(long n, int i)
{
	if (n <= 0)
	{
		if (i == 0)
			return (ft_printf_char('0'));
		return (i);
	}
	i = ft_printf_base10(n / 10, i + 1);
	ft_printf_char(n % 10 + 48);
	return (i);
}
