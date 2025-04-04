/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ararakel <ararakel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:03:03 by ararakel          #+#    #+#             */
/*   Updated: 2025/04/03 14:33:38 by ararakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_size(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_u(unsigned int nbr, int count)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count + 1] = '\0';
	while (count > i)
	{
		str[count -1] = (nbr % 10) + '0';
		nbr /= 10;
		count --;
	}
	return (str);
}

size_t	ft_printf_u(unsigned int nbr)
{
	int		i;
	char	*str;
	int		count;

	i = 0;
	if (nbr == 0)
		i += write(1, "0", 1);
	else
	{
		count = 0;
		count = (int)ft_count_size(nbr);
		str = ft_itoa_u(nbr, count);
		i += ft_putstr(str);
	}
	return (i);
}
