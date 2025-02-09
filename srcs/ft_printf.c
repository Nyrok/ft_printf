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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	void	*arg;

	va_start(args, format);
	len = 0;
	if (format == 0)
		return (-1);
	while (*format)
	{
		arg = NULL;
		if (*format == '%')
		{
			format++;
			len += format_conversion(arg, *format, args);
		}
		else
		{
			len++;
			write(1, format, 1);
		}
		format++;
	}
	return (len);
}
