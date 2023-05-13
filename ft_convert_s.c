/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:03:11 by prukngan          #+#    #+#             */
/*   Updated: 2023/05/13 14:08:39 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_s(char const *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		if (flags->point == -1 || flags->point >= 6)
			flags->point = 6;
		if (flags->left)
			len += write(1, "(null)", flags->point) + ft_printf_flags_s(flags);
		else if (!flags->left)
			len += ft_printf_flags_s(flags) + write(1, "(null)", flags->point);
		return (len);
	}
	if (flags->point == -1 || flags->point > (int)ft_strlen(str))
		flags->point = ft_strlen(str);
	return (ft_printf_s(str, flags));
}

int	ft_printf_s(char const *str, t_flags *flags)
{
	if (flags->left)
		return (write(1, str, flags->point) + ft_printf_flags_s(flags));
	return (ft_printf_flags_s(flags) + write(1, str, flags->point));
}

int	ft_printf_flags_s(t_flags *flags)
{
	int	len;

	len = 0;
	while (len < flags->width - flags->point)
		len += ft_printf_char(flags->blank);
	return (len);
}
