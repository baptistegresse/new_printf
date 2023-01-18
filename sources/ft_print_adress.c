/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:03:36 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/15 21:45:36 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr_base_adress(t_print *tab,
		unsigned long long number, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (number >= base_len)
	{
		ft_putnbr_base_adress(tab, number / base_len, base);
	}
	ft_putchar(base[number % base_len], tab);
}

void	ft_print_adress(t_print *tab)
{
	unsigned long long	ret;

	ret = va_arg(tab->args, unsigned long long);
	ft_putstr((unsigned char *)"0x", tab);
	ft_putnbr_base_adress(tab, ret, "0123456789abcdef");
}
