/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:37:16 by aceralin          #+#    #+#             */
/*   Updated: 2022/06/23 12:18:34 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int nb);
int	ft_putchar(char c);
int	ft_print_hex(unsigned int nbr, char type);
int	ft_print_ptr(unsigned long long nbr);

#endif