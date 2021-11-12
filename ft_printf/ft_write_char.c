#include "ft_printf.h"

int	write_char(char c, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += write(1, &c, 1);
	len += write_width(flags.width, 1, 0);
	if (flags.minus == 0)
		len += write (1, &c, 1);
	return (len);
}
