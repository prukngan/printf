/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:33:25 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/27 20:33:25 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_p(unsigned long long pt, t_flags *flags)
{
	if (pt == 0)
	{
		if (flags->point == -1 || flags->point >= 5)
		{
			flags->point = 5;
			if (flags->left)
				return (write(1, "(nil)", 5) + ft_printf_flags_x(flags));
			return (ft_printf_flags_x(flags) + write(1, "(nil)", 5));
		}
		return (0);
	}
	flags->before = '#';
	return (ft_convert_x('x', pt, flags));
}
