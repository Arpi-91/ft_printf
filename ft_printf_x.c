/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <ararakel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:55:21 by ararakel          #+#    #+#             */
/*   Updated: 2025/04/02 19:30:03 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void	ft_print_hex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16, format);
		ft_print_hex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
		{
			ft_putchar(nbr + '0');
		}
		else
		{
			if (format == 'x')
				ft_putchar((nbr - 10) + 'a');
			if (format == 'X')
				ft_putchar((nbr - 10) + 'A');
		}
	}		
}

size_t	ft_printf_x(unsigned int nbr, const char format)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = write(1, "0", 1);
	else
	{
		ft_print_hex(nbr, format);
		i += ft_hex_len(nbr);
	}
	return (i);
}
