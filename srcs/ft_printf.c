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

int	check_format(const char *format, ...)
{
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (format[len])
		len++;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (format[j] == '%')
				j++;
			else
				break ;
			j++;
		}
		if ((j - i) > 1 && (j - i) % 2 != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	void	*arg;

	va_start(args, format);
	len = 0;
	if (!format || !check_format(format))
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
