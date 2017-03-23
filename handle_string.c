/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:44 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:39:47 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s(t_struct *form, char *ch)
{
	char	*s;
	int		f;
	char	*b;

	form->plus = 0;
	form->space = 0;
	if (!form->p)
		return (ft_strnew(1));
	b = ((!ch) ? ft_strdup("(null)") : ft_strdup(ch));
	f = ft_strlen(b);
	if (form->min > form->p && form->min != 0 && form->p > 0)
		f = form->min;
	else if (form->p > form->min && form->p < (int)ft_strlen(b))
		f = form->p;
	if (form->p > (int)ft_strlen(b))
		form->p = 0;
	s = ft_strnew(f);
	(form->zero && !form->minus) ? ft_memset(s, '0', f) : ft_memset(s, ' ', f);
	if (form->p < (int)ft_strlen(b) && form->p > 0)
		ft_memset(b + form->p, '\0', ft_strlen(b) - form->p);
	(form->minus) ? (my_strcpy(s, b)) : (my_strcpy(s + (f - ft_strlen(b)), b));
	free(b);
	return (s);
}
