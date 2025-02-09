/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:32 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/31 15:11:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#define BASE_OCT "01234567"
#define BASE_DEC "0123456789"
#define BASE_HEX "0123456789abcdef"
#define BASE_HEX_UPPER "0123456789ABCDEF"

int	format_conversion(void *arg, char c, va_list args)
{
	if (c == 's')
		return (format_string(va_arg(args, char *)));
	else if (c == 'c')
		return (format_char(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (format_base(va_arg(args, int), BASE_DEC, 10));
	else if (c == 'x')
		return (format_base(va_arg(args, unsigned int), BASE_HEX, 16));
	else if (c == 'X')
		return (format_base(va_arg(args, unsigned int), BASE_HEX_UPPER, 16));
	else if (c == 'u')
		return (format_base(va_arg(args, unsigned int), BASE_DEC, 10));
	else if (c == 'p')
	{
		arg = va_arg(args, void *);
		if (!arg)
			return (write(1, "(nil)", 5));
		return (format_string("0x")
			+ format_pointer(arg, BASE_HEX, 16));
	}
	else if (c == 'o')
		return (format_base(va_arg(args, unsigned int), BASE_OCT, 8));
	else if (c == '%')
		return (format_char('%'));
	return (0);
}
