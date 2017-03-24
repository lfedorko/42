/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:25:47 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:25:48 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(intmax_t c)
{
	int			count;

	count = 0;
	if (c == 0)
		count++;
	while (c != 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

char		*myitoa(intmax_t n, t_struct *form)
{
	char		*str;
	int			count;
	int			i;
	intmax_t	num;

	i = 0;
	num = n;
	count = ft_size(num);
	if (num == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	str = (char *)malloc((count + 1) * sizeof(char));
	if (num < 0)
	{
		form->plus = 2;
		num = -num;
	}
	str[count] = '\0';
	count = count - 1;
	while (i <= count)
	{
		str[count] = (num % 10) + 48;
		num /= 10;
		count--;
	}
	return (str);
}

char		*my_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (dst + i + 1);
}

void		init_struct(t_struct *form)
{
	form->flag = 0;
	form->plus = 0;
	form->minus = 0;
	form->sharp = 0;
	form->space = 0;
	form->zero = 0;
	form->min = 0;
	form->p = -1;
	form->null = 0;
	ft_memset(form->len, 0, sizeof(form->len));
	form->conv = '\0';
}

size_t		ft_pow(size_t n, int p)
{
	int		i;
	size_t	k;

	i = 0;
	k = 1;
	if (p == 0)
		return (1);
	if (p == 1)
		return (n);
	while (i <= p)
	{
		k = k * n;
		i++;
	}
	return (k);
}
