/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:59:56 by aceralin          #+#    #+#             */
/*   Updated: 2022/11/20 21:40:50 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_format(const char type, va_list list_args)
{
	if (type == 'c')
		return (ft_print_char(va_arg(list_args, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(list_args, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(list_args, unsigned long long)));
	else if (type == 'd' || type == 'i' )
		return (ft_print_nbr(va_arg(list_args, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(list_args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(list_args, unsigned int), type));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list_args;
	int		len;

	va_start (list_args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(str[i + 1], list_args);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end (list_args);
	return (len);
}
