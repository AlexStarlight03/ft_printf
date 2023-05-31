/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:49:26 by adube             #+#    #+#             */
/*   Updated: 2023/01/25 13:55:53 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_number(int n);
int	ft_percent(void);
int	ft_ptr_print(unsigned long long ptr);
int	ft_print_string(char *str);
int	ft_uint_print(unsigned int n);
int	ft_hexaprint(unsigned int n, const char type);

#endif
