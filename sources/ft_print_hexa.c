/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:01:06 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/17 20:06:04 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(t_print *tab, unsigned int number, char *base)
{
	size_t		base_len;

	base_len = ft_strlen(base);
	if (number >= base_len)
	{
		ft_putnbr_base(tab, number / base_len, base);
	}
	ft_putchar(base[number % base_len], tab);
}

void	ft_print_hexa(t_print *tab, char *base)
{
	unsigned int	ret;
	unsigned char	*string;

	ret = va_arg(tab->args, unsigned int);
	string = ft_uitoh(ret);	
	ft_putnbr_base(tab, ret, base);
	free(string);
}
