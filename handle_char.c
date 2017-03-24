/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:36:14 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/24 16:36:17 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_char(t_struct *form)
{
	char *s;

	s = ft_strnew(1);
	*s = form->conv;
	form->plus = 0;
	form->sharp = 0;
	form->space = 0;
	form->p = -1;
	form->len[0] = '\0';
	return (s);
}

void		ft_putchar0(char *str, t_struct *form)
{
	if (form->minus == 1)
	{
		ft_putchar('\0');
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		ft_putchar('\0');
	}
}

static char	*zero_char(t_struct *form)
{
	char	*s;
	int		si;

	si = 1;
	if (form->min < 0)
	{
		form->minus = 1;
		form->min = -form->min;
	}
	if (form->min > 1)
		si = form->min;
	s = ft_strnew(si);
	if (si != 1)
	{
		(form->zero) ? ft_memset(s, '0', si - 1) : ft_memset(s, ' ', si - 1);
		form->flag = -2;
	}
	else
		form->flag = -1;
	form->min = 0;
	return (s);
}

char		*ft_c(t_struct *form, int ch)
{
	char *c;

	form->plus = 0;
	form->sharp = 0;
	form->space = 0;
	form->p = -1;
	if (ch == 0)
		return (zero_char(form));
	c = ft_strnew(1);
	*c = (char)ch;
	return (c);
}
