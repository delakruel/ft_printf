#include "ft_printf.h"

int	flag_dot(char *fmt, int i, t_flags *flags, va_list ap)
{
	i++;
	if (fmt[i] == '*')
	{
		flags->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(fmt[i]))
			flags->dot = (flags->dot * 10) + (fmt[i++] - '0');
	}
	return (i);
}

t_flags	flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.nul = 0;
	return (flags);
}

t_flags	flag_star(t_flags flags, va_list ap)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.nul = 0;
	}
	return (flags);
}

t_flags	flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	else
		flags.width = flags.width * 10 + (c - '0');
	return (flags);
}
