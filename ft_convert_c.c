/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:39:48 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/27 23:39:48 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_c(char c, t_flags *flags)
{
	if (flags->left)
		return (ft_printf_char(c) + ft_printf_flags_c(flags));
	return (ft_printf_flags_c(flags) + ft_printf_char(c));
}

int	ft_printf_flags_c(t_flags *flags)
{
	int	len;

	len = 0;
	while (len < flags->width - 1)
		len += ft_printf_char(flags->blank);
	return (len);
}

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}