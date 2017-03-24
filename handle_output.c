/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:36:51 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:36:54 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*define_len(t_struct *form, va_list argp)
{
	if (form->conv == 'x' || form->conv == 'X')
		return (itoa_b(form, va_arg(argp, void *), 16));
	if (form->conv == 'o' || form->conv == 'O')
		return (itoa_b(form, va_arg(argp, void *), 8));
	if (form->conv == 'u' || form->conv == 'U')
		return (itoa_b(form, va_arg(argp, void *), 10));
	if (form->conv == 'd' || form->conv == 'D')
		return (itoa_d(form, va_arg(argp, void *)));
	return (itoa_d(form, va_arg(argp, void *)));
}

static char	*handle_conversion(t_struct *form, va_list argp)
{
	if (form->conv == 'b')
		return (print_bi(va_arg(argp, size_t), form));
	else if (find_letter("dDioOuUxX", form->conv))
		return (define_len(form, argp));
	else if (form->conv == 'c' || form->conv == 'C')
		return (ft_c(form, va_arg(argp, int)));
	else if (form->conv == 'S'
		|| (form->conv == 's' && !ft_strcmp(form->len, "l")))
		return (ft_widechar_s(va_arg(argp, wchar_t *), form, 0, 0));
	else if (form->conv == 's')
		return (ft_s(form, va_arg(argp, char *)));
	else if (form->conv == '%')
		return (ft_c(form, '%'));
	else if (form->conv == 'p')
		return (itoa_base(va_arg(argp, long long), 16, form->conv, 1));
	else if (form->conv == 'c')
		return (ft_c(form, va_arg(argp, int)));
	else if (form->conv == 'n')
		return (print_n(va_arg(argp, int *), form));
	return (ft_char(form));
}

static int	check_flags(t_struct *form, int sizestr, char *s)
{
	int	size;

	if (form->conv == 'p')
		form->sharp = 1;
	if (form->min < 0)
	{
		form->minus = 1;
		form->min = -form->min;
	}
	if (form->p < 0)
		form->p = 0;
	size = compare(form->p, sizestr);
	if (size == form->p && (form->conv != 's' && ft_strcmp("", s)))
		form->zero = 0;
	if ((form->plus || form->space) && !(find_letter("oOxXpuU", form->conv)))
		size++;
	if (form->sharp && ((find_letter("Xxp", form->conv)
		&& form->p > (int)ft_strlen(s) && ft_strcmp(s, "0"))))
		size += 2;
	return (compare(size, form->min));
}

int			handle_output(va_list argp, t_struct *form, int b)
{
	int		size1;
	char	*s;

	form->flag = b;
	if (!form->conv)
		return (0);
	s = handle_conversion(form, argp);
	if (ft_strcmp(s, "0x0") == 0 && form->conv == 'p' && form->p == 0)
		s[2] = '\0';
	if (!ft_strcmp(s, "0") && !form->p && !form->min
		&& (!form->sharp || find_letter("xX", form->conv)))
	{
		free(s);
		return (0);
	}
	else if (!ft_strcmp(s, "0") && !form->p && form->min && !form->sharp)
		s = ft_memset(s, ' ', ft_strlen(s));
	size1 = check_flags(form, ft_strlen(s), s);
	fill_array(size1, s, form);
	if (form->flag == -1 || form->flag == -2)
		size1++;
	return (size1);
}
