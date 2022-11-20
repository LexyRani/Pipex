/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:52:45 by aceralin          #+#    #+#             */
/*   Updated: 2022/06/23 12:27:02 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_change_base_ptr(unsigned long long nbr, char *base, int bsize)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += ft_change_base_ptr (nbr / bsize, base, bsize);
	len += ft_putchar(base[nbr % bsize]);
	return (len);
}

int	ft_print_ptr(unsigned long long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	len += ft_print_str("0x");
	len += ft_change_base_ptr(nbr, "0123456789abcdef", 16);
	return (len);
}
