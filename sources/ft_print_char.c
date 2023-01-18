/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:55:29 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/18 12:40:49 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void ft_wdt_flag(t_print *tab, char charset)
{
	while (tab->wdt-- > tab->strlen)
		ft_putchar(charset, tab);
}

void	ft_print_char(t_print *tab)
{
	unsigned int	ret;

	ret = va_arg(tab->args, unsigned int);
	tab->strlen = 1;
	if (tab->dash)
		return (ft_putchar(ret, tab), ft_wdt_flag(tab, ' '));
	if (tab->wdt)
		return (ft_wdt_flag(tab,' '), ft_putchar(ret, tab));
	ft_putchar(ret, tab);
}
