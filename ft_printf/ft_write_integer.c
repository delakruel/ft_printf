#include "ft_printf.h"

static int	write_i3(char *str, int tmp, t_flags flags)
{
	int	len;

	len = 0;
	if (tmp < 0 && flags.dot >= 0)
		write(1, "-", 1);
	if (flags.dot >= 0)
		len += write_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	len += ft_putstr(str, ft_strlen(str));
	return (len);
}

static int	write_i2(char *str, int tmp, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += write_i3(str, tmp, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += write_width(flags.width, 0, 0);
	}
	else
		len += write_width(flags.width, ft_strlen(str), flags.nul);
	if (flags.minus == 0)
		len += write_i3(str, tmp, flags);
	return (len);
}

static int	write_i4(int tmp, t_flags flags, long in)
{
	int		len;
	char	*str;

	len = 0;
	if (in == 2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa((int)in);
	len += write_i2(str, tmp, flags);
	free(str);
	return (len);
}

int	write_int(int kek, t_flags flags)
{
	int		len;
	int		tmp;
	long	in;

	in = (long)kek;
	len = 0;
	tmp = in;
	if (flags.dot == 0 && in == 0)
	{
		len += write_width(flags.width, 0, 0);
		return (len);
	}
	if (in < 0 && (flags.dot >= 0 || flags.nul == 1))
	{
		if (flags.nul == 1 && flags.dot <= -1)
			ft_putstr("-", 1);
		flags.nul = 1;
		in *= -1;
		flags.width--;
		len++;
	}
	len += write_i4(tmp, flags, in);
	return (len);
}
