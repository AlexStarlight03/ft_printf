/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:46:44 by adube             #+#    #+#             */
/*   Updated: 2023/01/19 13:09:30 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_put_hexa(unsigned int n, const char type)
{
	if (n >= 16)
	{
		ft_put_hexa(n / 16, type);
		ft_put_hexa(n % 16, type);
	}
	else
	{
		if (n > 9)
		{
			if (type == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			else
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
		else
			ft_putchar_fd((n + '0'), 1);
	}
}

int	ft_hexaprint(unsigned int n, const char type)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hexa(n, type);
	return (ft_hexlen(n));
}
