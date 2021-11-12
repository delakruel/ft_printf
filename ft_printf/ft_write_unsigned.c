#include "ft_printf.h"

static int	uns_len(unsigned int u)
{
	int	i;

	i = 0;
	while (u != 0)
	{
		u /= 10;
		i++;
	}
	return (i);
}

static char	*uns_itoa(unsigned int u)
{
	int		l;
	char	*str;

	if (u == 0)
		return (ft_strdup("0"));
	l = uns_len(u);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (0);
	str[l] = '\0';
	while (u != 0)
	{
		str[--l] = u % 10 + '0';
		u /= 10;
	}
	return (str);
}

static int	write_u3(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
		len += write_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	len += ft_putstr(str, ft_strlen(str));
	return (len);
}

static int	write_u2(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += write_u3(str, flags);
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
		len += write_u3(str, flags);
	return (len);
}

int	write_uns_int(unsigned int u, t_flags flags)
{
	char	*str;
	int		len;

	len = 0;
	if (flags.dot == 0 && u == 0)
	{
		len += write_width(flags.width, 0, 0);
		return (len);
	}
	str = uns_itoa(u);
	len += write_u2(str, flags);
	free(str);
	return (len);
}
