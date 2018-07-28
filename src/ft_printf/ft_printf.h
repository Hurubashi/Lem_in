/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:00:32 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/21 19:24:37 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

# define SPEC_PART1(e) e != 'd' && e != 'i' && e != 'D' && e != 'u' && e != 'U'
# define SPEC_PART2(e) e != 'c' && e != 'C' && e != 's' && e != 'S' && e != 'x'
# define SPEC_PART3(e) e != 'X' && e != 'o' && e != 'O' && e != 'p' && e != '%'

# define ALL_SPEC(e) SPEC_PART1(e) && SPEC_PART2(e) && SPEC_PART3(e)

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define BRED		"\x1B[41m"
# define BGREEN		"\x1B[42m"
# define BYELLOW	"\x1B[43m"
# define BBLUE		"\x1B[44m"
# define BMAGENTA	"\x1B[45m"
# define BCYN		"\x1B[46m"
# define BWHIE		"\x1B[47m"
# define UNDER		"\e[4m"
# define BLINK		"\e[5m"
# define REVER		"\e[7m"
# define CONC		"\e[8m"
# define BOLD		"\e[1m"
# define DIM		"\e[2m"
# define NORM		"\e[24m"
# define RESET		"\x1B[0m"

typedef struct	s_strnlen
{
	size_t		place;
	size_t		count;
}				t_strnlen;

typedef struct	s_flags
{
	char		minus;
	char		plus;
	char		space;
	char		hashtag;
	char		zero;
}				t_flags;

typedef struct	s_extension
{
	size_t		width;
	size_t		precision;
	size_t		if_perc;
}				t_extension;

typedef enum	e_spec
{
	s_decimal,
	S_decimal,
	u_decimal,
	U_decimal,
	octal,
	O_octal,
	hex_l,
	hex_u,
	letter,
	w_letter,
	string,
	w_string,
	pointer,
	percent,
	invalid
}				t_spec;

typedef enum	e_lenght
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

typedef struct	s_settings
{
	t_strnlen	strnlen;
	t_length	length;
	t_spec		spec;
	t_flags		flags;
	t_extension	ext;
}				t_settings;

size_t			do_all(const char *format, va_list *args, size_t n);
void			ft_putnstr(const char *str, size_t len);
int				ft_printf(const char *format, ...);
void			hexprint_low(uintmax_t n);
void			hexprint_upp(uintmax_t n);
void			put_octal(intmax_t n);
t_flags			parse_flags(const char *str, t_flags flags);
t_flags			initialize_flags();
t_length		parse_length(const char *str, t_length length);
t_spec			parse_spec(char c);
size_t			len_to_spec(const char *format);
t_extension		parse_ext(const char *str, t_extension extension);
size_t			u_digit_len(uintmax_t n);
size_t			digit_len(long long n);
size_t			put_nchar(char c, size_t n);
void			ft_put_uintmax_t(uintmax_t n);
size_t			print_s_decimal(va_list args, t_settings settings);
size_t			print_u_decimal(va_list args, t_settings settings);
void			print_wchar(wint_t c);
size_t			wstr_len(const int *str);
size_t			wchar_len(int c);
size_t			print_wstring(va_list args, t_settings settings);
size_t			print_string(va_list args, t_settings settings);
size_t			print_letter(va_list args, t_settings settings);
char			*cut_str(const char *format);
size_t			extension_usigned(t_settings set, size_t len,
								size_t pers_len, intmax_t nb);
size_t			print_hex(va_list args, t_settings set);
size_t			print_oct(va_list args, t_settings settings);
size_t			percision_dist(t_extension ext, size_t len);
size_t			print_pointer(va_list args, t_settings settings);
size_t			extension_hex(t_settings settings, size_t len,
								size_t pers_len, uintmax_t nb);
size_t			extension_oct(t_settings set, size_t len,
								size_t pers_len, uintmax_t nb);
size_t			extension_dec(t_settings settings, size_t len,
								size_t pers_len, intmax_t nb);
void			extension_handle(t_settings settings, size_t len,
								size_t pers_len);

#endif
