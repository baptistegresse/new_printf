/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:57:36 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/18 12:06:11 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(t_print *tab, unsigned char *string)
{
	if ((tab->pnt || tab->zero) && string[0] == '-')
		ft_putstr(string + 1, tab);
	else
		ft_putstr(string, tab);
}

void	ft_print_number(t_print *tab)
{
	int				ret;
	unsigned char	*string;

	ret = va_arg(tab->args, int);
	string = ft_itoa(ret);
	ft_putnbr(tab, string);
	free(string);
}
