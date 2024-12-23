/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:41:09 by ancardos          #+#    #+#             */
/*   Updated: 2024/03/13 10:41:31 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char input, va_list args)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += print_char(va_arg(args, int));
	else if (input == 's')
		i += print_string(va_arg(args, char *));
	else if (input == 'p')
		i += print_pointer(va_arg(args, unsigned long), 87);
	else if (input == 'd' || input == 'i')
		i += print_int(va_arg(args, int));
	else if (input == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (input == 'x')
		i += print_hex(va_arg(args, unsigned int), 87);
	else if (input == 'X')
		i += print_hex(va_arg(args, unsigned int), 55);
	else if (input == '%')
		i += print_char('%');
	return (i);
}

int	ft_printf(const char *input, ...)
{
	unsigned int	i;
	va_list			args;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
			i += check_type(*(++input), args);
		else
			i += print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
