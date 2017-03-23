/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:28:02 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:28:04 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_b(t_struct *form, void *num, int s)
{
	if (form->len[0] == 'l' && form->len[1] == 'l')
		return (itoa_base((unsigned long long)num, s, form->conv, form->sharp));
	else if (form->len[0] == 'l' || form->conv == 'O' || form->conv == 'U')
		return (itoa_base((unsigned long)num, s, form->conv, form->sharp));
	else if (form->len[0] == 'h' && form->len[1] == 'h')
		return (itoa_base((unsigned char)num, s, form->conv, form->sharp));
	else if (form->len[0] == 'h')
		return (itoa_base((unsigned short)num, s, form->conv, form->sharp));
	else if (form->len[0] == 'j')
		return (itoa_base((uintmax_t)num, s, form->conv, form->sharp));
	else if (form->len[0] == 'z')
		return (itoa_base((size_t)num, s, form->conv, form->sharp));
	else
		return (itoa_base((unsigned int)num, s, form->conv, form->sharp));
}

char	*itoa_d(t_struct *form, void *num)
{
	if ((form->len[0] == 'l' && form->len[1] != 'l') || form->conv == 'D')
		return (myitoa((long)num, form));
	else if (form->len[0] == 'l' && form->len[1] == 'l')
		return (myitoa((long long)num, form));
	else if (form->len[0] == 'l' || form->conv == 'D')
		return (myitoa((long)num, form));
	else if (form->len[0] == 'h' && form->len[1] == 'h')
		return (myitoa((signed char)num, form));
	else if (form->len[0] == 'h')
		return (myitoa((signed short)num, form));
	else if (form->len[0] == 'j')
		return (myitoa((intmax_t)num, form));
	else if (form->len[0] == 'z')
		return (myitoa((size_t)num, form));
	else
		return (myitoa((int)num, form));
}
