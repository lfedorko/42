/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:58:50 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 19:58:45 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		b;
	char	*s;
	va_list	argp;

	b = 0;
	s = (char *)format;
	va_start(argp, format);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			i = to_struct(argp, &s, b, 0);
			b += i;
		}
		else
		{
			ft_putchar(*s);
			b++;
		}
		s++;
	}
	va_end(argp);
	return (b);
}
