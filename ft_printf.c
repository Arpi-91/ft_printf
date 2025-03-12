/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:27:21 by ararakel          #+#    #+#             */
/*   Updated: 2025/03/12 17:21:43 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_format(const char c, va_list args)
{
	char	*chr;
	int		len;

	len = 0;
	chr = va_arg(args, char *);
	if (c == 'c')
		len += ft_putchar((char)chr);
	else if (c == 's')
		len += ft_putstr(chr);
	else if (c == 'p')
	{
	}
	else if (c == 'i' || c == 'd' || c == 'u')
		len += ft_putnbr((int)(chr));
	/*else if (c == 'x' || c = 'X')
	{
		print_format_x(args);
	}*/
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *ptr_format, ...)
{
	va_list			args;
	unsigned int	i;
	int				len;

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
/*
int	main(void)
{
//	ft_printf("hello ee 1- %s aaa 2-%c e\n","", '1');
//	printf("%u", 0);
//	ft_printf("helloee 2-%ciiii",'Z');
	ft_printf("%d\n", 122);
	ft_printf(" %s,  %s\n", "","-");
	//printf("%d",printf(" %d\n", -214748364));
//	printf("%d", ft_printf(" %d\n", -214748364));
	print(" %d ", 9223372036854775807LL);
}
*/
