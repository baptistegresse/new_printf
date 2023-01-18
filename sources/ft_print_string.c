/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:56:47 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/18 14:12:33 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void ft_wdt_flag(t_print *tab, char charset)
{
	if (tab->dash && !tab->prc && tab->wdt >= tab->strlen)
		while (tab->wdt-- > tab->strlen)
			ft_putchar(charset, tab);
	else if ((tab->prc || tab->dash) && (tab->prc < tab->strlen))
		while (tab->wdt-- > tab->prc)
			ft_putchar(charset, tab);
	else
		while (tab->wdt-- > tab->strlen)
			ft_putchar(charset, tab);
}

static void ft_prc_flag(t_print *tab, unsigned char *string)
{
	int		tempory_prc;

	tempory_prc = tab->prc;
	if (tab->prc < tab->strlen)
		while (tempory_prc--)
			ft_putchar(*string++, tab);
	else
		ft_putstr(string, tab);
}

void	ft_print_string(t_print *tab)
{
	unsigned char	*ret;

	ret = va_arg(tab->args, unsigned char *);
	if (!ret)
		ret = (uchar)"(null)";
	tab->strlen = ft_strlen((char *)ret);
	if (tab->pnt && tab->dash)
		return (ft_prc_flag(tab, ret), ft_wdt_flag(tab, ' '));
	if (tab->pnt && tab->wdt)
		return (ft_wdt_flag(tab, ' '), ft_prc_flag(tab, ret));
	if (tab->pnt)
		return (ft_prc_flag(tab, ret));
	if (tab->dash && tab->wdt > tab->strlen)
		return (ft_putstr(ret, tab), ft_wdt_flag(tab, ' '));
	if (tab->wdt && !tab->dash)
		return (ft_wdt_flag(tab, ' '), ft_putstr(ret, tab));
	ft_putstr(ret, tab);
}
