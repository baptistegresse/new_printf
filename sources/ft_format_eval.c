/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_eval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:58:25 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/18 14:00:55 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_is_not_valid_format(char format)
{
	if (format != 'c' && format != 's' && format != 'd'
		&& format != 'i' && format != 'u' && format != 'x'
		&& format != 'X' && format != 'p' && format != '%')
			return (1);
	return (0);
}

static int	ft_get_prc_wdt(int *tab, const char *format, int index)
{
	unsigned char	*numbers;
	int				index_numbers;

	index_numbers = index;
	while (ft_isdigit(format[index_numbers]))
		index_numbers++;
	numbers = malloc(sizeof(char) * (index_numbers - index + 1));
	if (!numbers)
		return (0);
	index_numbers = 0;
	while (ft_isdigit(format[index]))
		numbers[index_numbers++] = format[index++];
	numbers[index_numbers] = 0;
	*tab = ft_atoi((char *)numbers);
	free(numbers);
	return (index - 1);
}

static int	ft_format_flags(t_print *tab, const char *format, int index)
{
	while (ft_is_not_valid_format(format[index]))
	{
		if (format[index] == '#')
			tab->sharp = 1;
		if (format[index] == '0')
			tab->zero = 1;
		if (format[index] == '.')
			tab->pnt = 1;
		if (format[index] == '-')
			tab->dash = 1;
		if (format[index] == '+')
			tab->plus = 1;
		if (format[index] == ' ')
			tab->sp = 1;
		if (format[index] >= '1' && format[index] <= '9' && !tab->pnt)
			index = ft_get_prc_wdt(&tab->wdt, format, index);
		if (format[index] >= '1' && format[index] <= '9' && tab->pnt)
			index = ft_get_prc_wdt(&tab->prc, format, index);
		index++;
	}
	return (index);
}

int	ft_format_eval(t_print *tab, const char *format, int index)
{
	index = ft_format_flags(tab, format, index);
	if (format[index] == 'c')
		ft_print_char(tab);
	if (format[index] == 's')
		ft_print_string(tab);
	if (format[index] == 'd' || format[index] == 'i')
		ft_print_number(tab);
	if (format[index] == 'u')
		ft_print_hexa(tab, "0123456789");
	if (format[index] == 'x')
		ft_print_hexa(tab, "0123456789abcdef");
	if (format[index] == 'X')
		ft_print_hexa(tab, "0123456789ABCDEF");
	if (format[index] == 'p')
		ft_print_adress(tab);
	if (format[index] == '%')
		ft_putchar('%', tab);
	return (index);
}
