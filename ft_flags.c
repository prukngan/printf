/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:57:43 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/24 01:57:43 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'p'
		|| c == 'x' || c == 'X' || c == 'f' || c == 's' || c == '%')
		return (1);
	return (0);
}

void	ft_set_flags(t_flags *flags)
{
	flags->left = 0;
	flags->space = 0;
	flags->width = 0;
	flags->blank = ' ';
	flags->before = 0;
	flags->point = -1;
	flags->star = 0;
}

const char	*ft_flags(const char *s, va_list *lst, t_flags *flags)
{
	ft_set_flags(flags);
	while (*s && !ft_istype(*s))
	{
		if (*s == '+' || *s == '#')
			flags->before = *s;
		else if (*s == '-')
			flags->left = 1;
		else if (*s == '0')
			flags->blank = '0';
		else if (*s == ' ')
			flags->space = 1;
		else
			break ;
		s++;
	}
	while (*s && !ft_istype(*s))
		s = ft_flags_star(s, lst, flags);
	if (ft_istype(*s))
		return (s);
	return (0);
}

const char	*ft_flags_star(const char *s, va_list *lst, t_flags *flags)
{
	if (*s == '.')
	{
		s++;
		if (*s != '*')
			return (ft_flags_atoi(s, &(flags->point)));
		flags->point = va_arg(*lst, int);
		if (flags->point < 0)
			flags->point = -1;
	}
	else
	{
		if (*s != '*')
			return (ft_flags_atoi(s, &(flags->width)));
		flags->width = va_arg(*lst, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->left = 1;
		}
	}
	return (s + 1);
}

const char	*ft_flags_atoi(const char *s, int *num)
{
	int	n;

	n = 0;
	while (*s >= '0' && *s <= '9')
		n = (n * 10) + (*s++ - 48);
	*num = n;
	return (s);
}
