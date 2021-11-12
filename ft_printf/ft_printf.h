#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		minus;
	int		nul;
	int		dot;
	int		star;
	int		width;
	char	type;
}	t_flags;

t_flags	init_flags(t_flags flags);
int		found_conv(char c);
int		found_flag(char c);
int		ft_isdigit(int c);
int		flag_dot(char *fmt, int i, t_flags *flags, va_list ap);
t_flags	flag_minus(t_flags flags);
t_flags	flag_star(t_flags flags, va_list ap);
t_flags	flag_digit(char c, t_flags flags);
int		write_width(int width, int minus, int nul);
int		write_char(char c, t_flags flags);
int		write_string(char *str, t_flags flags);
int		ft_putstr(char *s, int dot);
int		write_prec_end(char *str, int prec);
int		write_pointer(size_t s, t_flags flags);
int		write_int(int in, t_flags flags);
int		write_uns_int(unsigned int u, t_flags flags);
int		write_hex(unsigned int hex, t_flags flags);
int		write_percent(t_flags flags);
int		ft_printf(const char *fmt, ...);

#endif