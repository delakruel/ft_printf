#include "ft_printf.h"

int	ft_process(int c, t_flags flags, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = write_char(va_arg(ap, int), flags);
	else if (c == 's')
		len = write_string(va_arg(ap, char *), flags);
	else if (c == 'p')
		len = write_pointer(va_arg(ap, size_t), flags);
	else if (c == 'd' || c == 'i')
		len = write_int(va_arg(ap, int), flags);
	else if (c == 'u')
		len = write_uns_int(va_arg(ap, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		len = write_hex(va_arg(ap, unsigned int), flags);
	else if (c == '%')
		len = write_percent(flags);
	return (len);
}

int	flag_pars(char *fmt, t_flags *flags, int i, va_list ap)
{
	while (fmt[i])
	{
		if (!ft_isdigit(fmt[i]) && !found_conv(fmt[i])
			&& !found_flag(fmt[i]))
			break ;
		if (fmt[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->nul = 1;
		if (fmt[i] == '.')
			i = flag_dot(fmt, i, flags, ap);
		if (fmt[i] == '-')
			*flags = flag_minus(*flags);
		if (fmt[i] == '*')
			*flags = flag_star(*flags, ap);
		if (ft_isdigit(fmt[i]))
			*flags = flag_digit(fmt[i], *flags);
		if (found_conv(fmt[i]))
		{
			flags->type = fmt[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	fmt_pars(va_list ap, char *fmt)
{
	int		len;
	int		i;
	t_flags	flags;

	i = 0;
	len = 0;
	while (fmt[i])
	{
		flags = init_flags(flags);
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i = flag_pars(fmt, &flags, ++i, ap);
			if (found_conv(fmt[i]))
				len += ft_process(flags.type, flags, ap);
			else if (fmt[i])
				len += write(1, &fmt[i], 1);
		}
		else if (fmt[i] != '%')
			len += write(1, &fmt[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;
	char	*format;

	format = ft_strdup(fmt);
	va_start(ap, fmt);
	len = fmt_pars(ap, format);
	va_end(ap);
	free(format);
	return (len);
}
