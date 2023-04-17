/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:59:05 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/16 01:59:05 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include <unistd.h>
# include <stdarg.h>

extern int len;

int	ft_printf(char const *s, ...);
void	ft_check_type(int const c, va_list *lst);

void	ft_printf_base10(long n, int c);
char	*ft_utoa(unsigned int n);

void	ft_printf_base16(unsigned long long pt, int const c);

void	ft_printf_str(char *str);

#endif