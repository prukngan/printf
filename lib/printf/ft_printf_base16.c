/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:29:05 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/17 00:29:05 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_printf_base16(unsigned long long pt, int const c)
{
	if (pt == 0)
		return ;
	ft_printf_base16(pt / 16, c);
	if  (c == 'X')
		len += write(1, &"0123456789ABCDEF"[pt % 16], 1);
	else
		len += write(1, &"0123456789abcdef"[pt % 16], 1);
}