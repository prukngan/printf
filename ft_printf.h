/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:59:05 by prukngan          #+#    #+#             */
/*   Updated: 2023/04/16 01:59:05 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	unsigned int	left;
	unsigned int	space;
	int				point;
	int				width;
	char			blank;
	char			before;
	int				star;
}	t_flags;

int				ft_printf(char const *s, ...);
int				ft_convert(char const c, t_flags *flags, va_list *lst);

const char		*ft_flags(const char *s, va_list *lst, t_flags *flags);
void			ft_set_flags(t_flags *flags);
const char		*ft_flags_star(const char *s, va_list *lst, t_flags *flags);
const char		*ft_flags_atoi(const char *s, int *num);
int				ft_istype(char c);

unsigned long	ft_strlen(const char *str);
int				ft_llonglen(long long num);
int				ft_baselen(unsigned long long num, unsigned int base);

int				ft_convert_c(int c, t_flags *flags);
int				ft_printf_flags_c(t_flags *flags);
int				ft_printf_char(int c);

int				ft_convert_d(long num, t_flags *flags);
int				ft_printf_flags_d(t_flags *flags);
int				ft_printf_arg_d(long num, int lenarg, t_flags *flags);
int				ft_printf_d(long num, int lenarg, t_flags *flags);
int				ft_printf_base10(long n, int i);

int				ft_convert_p(unsigned long long pt, t_flags *flags);

int				ft_convert_s(char const *str, t_flags *flags);
int				ft_printf_flags_s(t_flags *flags);
int				ft_printf_s(char const *str, t_flags *flags);

int				ft_convert_x(int c, unsigned long long num, t_flags *flags);
int				ft_printf_flags_x(t_flags *flags);
int				ft_printf_arg_x(int c, unsigned long long num, t_flags *flags);
int				ft_printf_x(int c, unsigned long long num, t_flags *flags);
int				ft_printf_base16(unsigned long long n, int c, int i);

#endif