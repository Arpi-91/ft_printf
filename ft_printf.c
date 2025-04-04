/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:57:42 by ararakel          #+#    #+#             */
/*   Updated: 2025/04/03 15:57:49 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_format(const char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		len += ft_printf_u(va_arg(args, unsigned int));
	else if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		len += ft_printf_p(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		len += ft_printf_x(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *ptr_format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, ptr_format);
	i = 0;
	len = 0;
	while (ptr_format[i] != '\0')
	{
		if (ptr_format[i] == '%')
		{
			i++;
			len += define_format(ptr_format[i], args);
		}
		else
		{
			len += write(1, &ptr_format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
