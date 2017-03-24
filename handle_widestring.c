/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_widestring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:42:34 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/24 16:42:36 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_wide(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	return (0);
}

static char	*ft_widechar_s2(wchar_t c)
{
	int		size;
	int		key;
	char	*s;

	size = count_wide(c);
	s = ft_strnew(size);
	if (size == 4)
		key = 240;
	if (size == 3)
		key = 224;
	if (size == 2)
		key = 192;
	if (size == 1)
		*s = c;
	else
		s[0] = ((c >> (6 * (size - 1))) | key);
	while (size > 1)
	{
		s[size - 1] = ((63 & c) | 128);
		c = c >> 6;
		size--;
	}
	return (s);
}

static char	*ft_record_w(wchar_t *s, char *s1)
{
	int		i;
	char	*tmp;
	char	*onechar;

	i = 0;
	tmp = s1;
	while (s[i] != '\0')
	{
		onechar = ft_widechar_s2(s[i]);
		ft_strncpy(tmp, onechar, count_wide(s[i]));
		tmp = tmp + count_wide(s[i]);
		free(onechar);
		i++;
	}
	return (s1);
}

char		*ft_widechar_s(wchar_t *s, t_struct *form, int len, int i)
{
	int		tmpp;
	int		tmpp2[2];

	tmpp2[1] = -1;
	tmpp2[0] = 0;
	form->flag = 0;
	if (!s)
		return (ft_s(form, (char *)s));
	if (!form->p)
		return (ft_strnew(1));
	while (s[i] != '\0')
	{
		tmpp = count_wide(s[i]);
		if (tmpp2[0] + tmpp <= form->p && form->p > 0 && (i - tmpp2[1] == 1))
		{
			tmpp2[0] += tmpp;
			tmpp2[1] = i;
		}
		len += tmpp;
		i++;
	}
	if (tmpp2[0] < form->p && form->p > 0)
		form->p = tmpp2[0];
	return (ft_ws(form, ft_record_w(s, ft_strnew(len))));
}

char		*ft_ws(t_struct *form, char *ch)
{
	char	*s;
	int		f;
	char	*b;

	form->plus = 0;
	form->space = 0;
	b = ft_strdup(ch);
	f = ft_strlen(b);
	if (form->min >= form->p && form->min != 0 && form->p > 0)
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
	free(ch);
	free(b);
	return (s);
}
