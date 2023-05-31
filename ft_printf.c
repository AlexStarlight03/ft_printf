/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:54:09 by adube             #+#    #+#             */
/*   Updated: 2023/01/19 13:09:20 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_type(va_list arg, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_char(va_arg(arg, int));
	else if (type == 's')
		len += ft_print_string(va_arg(arg, char *));
	else if (type == 'p')
		len += ft_ptr_print(va_arg(arg, unsigned long long));
	else if (type == 'd' || type == 'i')
		len += ft_print_number(va_arg(arg, int));
	else if (type == 'u')
		len += ft_uint_print(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X')
		len += ft_hexaprint(va_arg(arg, unsigned int), type);
	else if (type == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len_total;
	va_list	arg;

	i = 0;
	len_total = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_total = len_total + ft_type(arg, str[i + 1]);
			i++;
		}
		else
			len_total = len_total + ft_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len_total);
}
