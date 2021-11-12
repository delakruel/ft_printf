#include "ft_printf.h"

static int	minus_exist_string(t_flags flags, char *str)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
	{
		len += write_width(flags.dot, ft_strlen(str), 0);
		len += ft_putstr(str, flags.dot);
	}
	else
		len += ft_putstr(str, ft_strlen(str));
	return (len);
}

int	write_string(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		len += minus_exist_string(flags, str);
	if (flags.dot >= 0)
		len += write_width(flags.width, flags.dot, 0);
	else
		len += write_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		len += minus_exist_string(flags, str);
	return (len);
}
