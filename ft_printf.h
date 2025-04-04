/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:57:07 by ararakel          #+#    #+#             */
/*   Updated: 2025/04/03 15:57:14 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *ptr_format, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnbr(int nbr);
size_t	ft_printf_u(unsigned int nbr);
size_t	ft_printf_x(unsigned int nbr, const char format);
size_t	ft_printf_p(void *ptr);

#endif
