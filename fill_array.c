/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:28:41 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:28:43 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_p(char **s, t_struct *form)
{
	int add;

	add = 0;
	if (find_letter("xXp", form->conv) && (form->sharp))
	{
		add = 2;
		if (form->zero && !form->minus)
		{
			form->p = form->min - add;
			form->zero = 0;
		}
	}
	if (form->p == -1 || form->conv == 's')
		return ;
	if ((int)ft_strlen(*s) - add > form->p)
		return ;
	*s = ft_realloc(*s, form->p + add);
	*s = *s + add;
	*s = record1(*s, form->p - (ft_strlen(*s)), ft_strlen(*s));
	*s = *s - add;
}

static void	fill_str_m(char **buff, char **s, t_struct *form)
{
	if ((form->plus || form->space)
		&& !find_letter("xXOopuUc", form->conv))
	{
		if (form->plus == 1)
			**buff = '+';
		else if (form->plus == 2)
			**buff = '-';
		else if (form->space)
			**buff = ' ';
		*buff = *buff + 1;
	}
	*buff = my_strcpy(*buff, *s);
}

static void	fill_str(char **buff, char **s, t_struct *form)
{
	int i;

	if (form->zero)
		i = 0;
	else
		i = ft_strlen(*buff) - ft_strlen(*s) - 1;
	if (i < 0)
		i = 0;
	if ((form->plus || form->space)
		&& !find_letter("xXOopuUc", form->conv))
	{
		if (form->plus == 1)
			*(*buff + i) = '+';
		else if (form->plus == 2)
			*(*buff + i) = '-';
		else if (form->space)
			*(*buff + i) = ' ';
	}
	*buff = my_strcpy((*buff + ft_strlen(*buff) - ft_strlen(*s)), *s);
}

void		fill_array(int size, char *s, t_struct *form)
{
	char *str;
	char *buff;

	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	buff = str;
	if (form->flag != -1)
		str = ft_memset(str, ' ', size);
	if ((form->zero && form->min && !form->minus)
		|| (find_letter("xX", form->conv) && !ft_strcmp("0", s) && form->sharp))
		str = ft_memset(str, '0', size);
	fill_p(&s, form);
	(form->minus) ? fill_str_m(&buff, &s, form) : fill_str(&buff, &s, form);
	if (form->flag == -1 || form->flag == -2)
		ft_putchar0(str, form);
	else
		ft_putstr(str);
	free(s);
	free(str);
}
