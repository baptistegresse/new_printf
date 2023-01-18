/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:54:25 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/18 12:18:51 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_init_tab(t_print *tab)
{
    tab->sp = 0;
	tab->wdt = 0;
    tab->prc = 0;
    tab->pnt = 0;
	tab->zero = 0;
    tab->dash = 0;
    tab->sign = 0;
	tab->strlen = 0;
    tab->is_zero = 0;
}

int	ft_printf(const char *format, ...)
{
	t_print	tab;
	size_t	index;

	tab.tl 	= 0;
	index 	= -1;
	va_start(tab.args, format);
	while (format[++index])
	{
		ft_init_tab(&tab);
		if (format[index] == '%')
			index = ft_format_eval(&tab, format, index + 1);
		else
			ft_putchar(format[index], &tab);
	}
	va_end(tab.args);
	return (tab.tl);
}
