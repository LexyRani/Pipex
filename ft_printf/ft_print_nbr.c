/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:52:50 by aceralin          #+#    #+#             */
/*   Updated: 2022/06/23 12:13:28 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_nbr( int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb = nb * (-1);
		len += ft_putchar('-');
	}
	if (nb > 9)
	{
		len += ft_print_nbr(nb / 10);
		len += ft_print_nbr(nb % 10);
	}		
	else
		len += ft_putchar(nb + '0');
	return (len);
}
