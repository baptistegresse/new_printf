/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:57:58 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/18 14:00:44 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_print
{
	va_list		args;
      int   wdt;        // width
      int   prc;        // precision
      int   zero;       // zero padding
      int   pnt;        // .
      int   dash;       // -
      int   sharp;      // #
      int   plus;       // +
      int   tl;         // total_length (return value)
      int   sign;       // pos or neg number
      int   is_zero;    // is number zero
      int   sp;         // space flag ' '
      int   strlen;    // length of string
}				t_print;

typedef unsigned char * uchar;

// typedef enum s_bool
// {
//       false,
//       true
// }           t_bool;

int			ft_printf(const char *format, ...)\
				__attribute__((format (printf, 1, 2)));
int			ft_format_eval(t_print *tab, const char *format, int index);

void			ft_putchar(char character, t_print *tab);
void			ft_putstr(unsigned char *string, t_print *tab);
void			ft_putnbr(t_print *tab, unsigned char *string);
void			ft_putnbr_base(t_print *tab, unsigned int number, char *base);

void			ft_print_char(t_print *tab);
void			ft_print_string(t_print *tab);
void			ft_print_number(t_print *tab);
void			ft_print_hexa(t_print *tab, char *base);
void			ft_print_adress(t_print *tab);

unsigned char	*ft_uitoh(unsigned long long nb);

#endif