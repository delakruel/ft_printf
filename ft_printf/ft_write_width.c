#include "ft_printf.h"

int	write_width(int width, int minus, int nul)
{
	int	len;

	len = 0;
	while (width > minus)
	{
		if (nul)
			write (1, "0", 1);
		else
			write (1, " ", 1);
		width--;
		len++;
	}
	return (len);
}
