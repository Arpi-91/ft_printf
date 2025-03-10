/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:27:21 by ararakel          #+#    #+#             */
/*   Updated: 2025/03/10 20:56:52 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	define_format(const char c, va_list args)
{
	char chr;
	chr = va_arg(args, int);
	if (c == 'c')
	{
		//write(1, &chr, 1 );
		ft_putchar(chr);
	}
	/*else if (c == 's')
	{
		print_format_s(args);
	}else if (c == 'p')
	{
		print_format_p(args);
	}else if (c == 'i' || c == 'd')
	{
		print_format_i(args);
	}else if (c = 'u')
	{
		print__format_u(args);
	}else if (c == 'x' || c = 'X')
	{
		print_format_x(args);
	}else (c == '%')*/
}

int	ft_printf(const char *ptr_format, ...)
{
	va_list args;
	va_start(args, ptr_format);

	unsigned int i;
//	const char *start;

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

int	main(void)
{
	ft_printf("hello %c ee %c e", 'Y', 'Z');
}

