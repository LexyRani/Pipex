/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:52:53 by aceralin          #+#    #+#             */
/*   Updated: 2022/06/23 12:23:04 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_change_base(unsigned int nbr, char *base, int bsize)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += ft_change_base(nbr / 16, base, 16);
	len += ft_putchar(base[nbr % bsize]);
	return (len);
}

int	ft_print_hex(unsigned int nbr, char type)
{
	int	len;

	len = 0;
	if (type == 'x')
		len += ft_change_base(nbr, "0123456789abcdef", 16);
	else if (type == 'X')
		len += ft_change_base(nbr, "0123456789ABCDEF", 16);
	return (len);
}
