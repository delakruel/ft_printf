#include "ft_printf.h"

int	write_percent(t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += ft_putstr("%", 1);
	len += write_width(flags.width, 1, flags.nul);
	if (flags.minus == 0)
		len += ft_putstr("%", 1);
	return (len);
}
