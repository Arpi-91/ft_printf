/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:58:00 by ararakel          #+#    #+#             */
/*   Updated: 2025/04/03 16:16:08 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		i ++;
	}
	return (i);
}

static void	print_ptr(unsigned long ptr)
{
	char	c;

	if (ptr >= 16)
	{
		print_ptr(ptr / 16);
		print_ptr(ptr % 16);
	}
	else
	{	
		if (ptr <= 9)
			c = ptr + '0';
		else
			c = (ptr - 10) + 'a';
		write(1, &c, 1);
	}
}

size_t	ft_printf_p(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += ptr_len((unsigned long)ptr);
		print_ptr((unsigned long)ptr);
	}
	return (len);
}
