/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:59:18 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/17 22:30:29 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long len(long long nb)
{
	unsigned long long	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static unsigned char	*if_zero(void)
{
	unsigned char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

unsigned char	*ft_uitoh(unsigned long long nb)
{
	unsigned char		*str;
	long long			n;
	unsigned long long	i;

	n = nb;
	i = len(n);
	if (n == 0)
		return (if_zero());
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

void	ft_putchar(char character, t_print *tab)
{
	tab->tl += write(1, &character, 1);
}

void	ft_putstr(unsigned char *string, t_print *tab)
{
	size_t	index;

	index = 0;
	while (string[index])
		ft_putchar(string[index++], tab);
}


