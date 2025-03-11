/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:27:21 by ararakel          #+#    #+#             */
/*   Updated: 2025/03/11 18:15:38 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	define_format(const char c, va_list args)
{
	char *chr;
	chr = va_arg(args, char *);
	if (c == 'c')
	{
		ft_putchar((char)chr);
	}else if (c == 's')
	{
		ft_putstr(chr);
	}else if (c == 'p')
	{
	//	print_format_p(args);
	}else if (c == 'i' || c == 'd' || c == 'u')
	{
		ft_putnbr((int)(chr));
	//	print_format_int(args, c);
	}
	/*else if (c == 'x' || c = 'X')
	{
		print_format_x(args);
	}else (c == '%')*/
	//chr = va_arg(args, int);
}

int	ft_printf(const char *ptr_format, ...)
{
	va_list args;
	va_start(args, ptr_format);

	unsigned int i;
 
	i = 0;

	while (ptr_format[i] != '\0')
	{
		if (ptr_format[i] == '%')
		{
			i++;
			define_format(ptr_format[i], args);

		}
		else
		{
			write(1, &ptr_format[i], 1);
		}
		i++;
	}

	//va_arg(start, int);
	va_end(args);
	return(1);
}
/*
int	main(void)
{
	ft_printf("hello ee 1- %s aaa 2-%c e\n","", '1');
//	printf("%u", 0);
//	ft_printf("helloee 2-%ciiii",'Z');
	//ft_printf("%d", 122);
	ft_printf(" %s\n", "aaa");
	printf(" %s", "sss");
}
*/
