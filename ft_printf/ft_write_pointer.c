#include "ft_printf.h"

static char	*conversion(size_t tmp, int len, char *str)
{
	len--;
	while (tmp != 0)
	{
		if ((tmp % 16) < 10)
			str[len] = (tmp % 16) + 48;
		else
			str[len] = (tmp % 16) + 87;
		tmp /= 16;
		len--;
	}
	return (str);
}

static char	*dec_to_hex(size_t s)
{
	int		len;
	char	*str;
	size_t	tmp;

	tmp = s;
	str = 0;
	len = 0;
	if (s == 0)
		return (ft_strdup("0"));
	while (s != 0)
	{
		s /= 16;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	str = conversion(tmp, len, str);
	return (str);
}

static int	write_p2(char *p, t_flags flags)
{
	int	len;

	len = 0;
	len += ft_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		len += write_width(flags.dot, ft_strlen(p), 1);
		len += ft_putstr(p, flags.dot);
	}
	else
		len += ft_putstr(p, ft_strlen(p));
	return (len);
}

int	write_pointer(size_t s, t_flags flags)
{
	int		len;
	char	*p;

	len = 0;
	if (s == 0 && flags.dot == 0)
	{
		len += ft_putstr("0x0", 3);
		return (len);
	}
	p = dec_to_hex(s);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		len += write_p2(p, flags);
	len += write_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		len += write_p2(p, flags);
	free(p);
	return (len);
}
