/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:26:54 by ararakel          #+#    #+#             */
/*   Updated: 2025/03/10 20:54:24 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);

#endif
