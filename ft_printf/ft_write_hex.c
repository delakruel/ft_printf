#include "ft_printf.h"

static int	write_h3(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
		len += write_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	len += ft_putstr(str, ft_strlen(str));
	return (len);
}

static int	write_h2(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += write_h3(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width = flags.width - flags.dot;
		len += write_width(flags.width, 0, 0);
	}
	else
		len += write_width(flags.width, ft_strlen(str), flags.nul);
	if (flags.minus == 0)
		len += write_h3(str, flags);
	return (len);
}

static char	*hex_itoa2(unsigned int tmp, char *str, int len, char k)
{
	int	b_s;

	b_s = 55;
	if (k == 'x')
		b_s = 87;
	len--;
	while (tmp != 0)
	{
		if ((tmp % 16) < 10)
			str[len] = tmp % 16 + 48;
		else
			str[len] = tmp % 16 + b_s;
		tmp /= 16;
		len--;
	}
	return (str);
}

static char	*hex_itoa(unsigned int hex, t_flags flags)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	len = 0;
	tmp = hex;
	if (hex == 0)
		return (ft_strdup("0"));
	while (hex != 0)
	{
		hex /= 16;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	str = hex_itoa2(tmp, str, len, flags.type);
	return (str);
}

int	write_hex(unsigned int hex, t_flags flags)
{
	int		len;
	char	*str;

	len = 0;
	if (flags.dot == 0 && hex == 0)
		return (write_width(flags.width, 0, 0));
	str = hex_itoa(hex, flags);
	len += write_h2(str, flags);
	free(str);
	return (len);
}
