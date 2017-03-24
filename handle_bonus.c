/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:33:12 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:33:14 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_bi(size_t val, t_struct *form)
{
	int		two;
	int		inpow;
	char	*s;

	two = 2;
	inpow = 0;
	form->p = 0;
	while (ft_pow(two, inpow) <= val)
		inpow++;
	s = ft_strnew(inpow + 1);
	while (inpow > -1)
	{
		s[inpow] = (val % 2) + '0';
		val /= 2;
		inpow--;
	}
	return (s);
}

char	*print_n(int *type, t_struct *form)
{
	*type = form->flag;
	init_struct(form);
	return (ft_strnew(1));
}

char	*iterator(char *s)
{
	while (*s >= '0' && *s <= '9')
		s++;
	s--;
	return (s);
}
