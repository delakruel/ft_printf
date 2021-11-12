#include "ft_printf.h"

t_flags	init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.nul = 0;
	flags.dot = -1;
	flags.star = 0;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int	found_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	found_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}
