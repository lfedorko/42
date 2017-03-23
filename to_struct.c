/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:40:45 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:40:49 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void flags_to_struct(t_struct *form, char c, char prev)
{
	if (c == '-')
		form->minus = 1;
	else if (c == '+')
		form->plus = 1;
	else if (c == ' ')
		form->space = 1;
	else if (c == '#')
		form->sharp = 1;
	else if (c == '0' && prev != '.' && form->p < 0)
		form->zero = 1;
}

static char	*digit_to_struct(t_struct *form, char *s, va_list argp)
{
	if (*s == '.')
	{
		form->zero = 0;
		s++;
		if (*s == '*')
			form->p = va_arg(argp, int);
		else if ((form->p = ft_atoi(s)))
		{
			while (*s >= '0' && *s <= '9')
				s++;
			s--;
		}
		if (form->p < 0)
			form->zero = 1;
	}
	else if ((*s >= '1' && *s <= '9') || *s == '*')
	{
		if (*s == '*')
			form->min = va_arg(argp, int);
		else if ((form->min = ft_atoi(s)))
		{
			while (*s >= '0' && *s <= '9')
				s++;
			s--;
		}
	}
	return (s);
}

static void	ll_hh(char c, t_struct *f)
{
	static int l;
	static int h;

	if (c == 'l')
		l += 1;
	else if (c == 'h')
		h += 1;
	if(f->flag)
	{
		if (f->len[0] == 'l')
		{
			ft_memset(f->len, '\0', ft_strlen(f->len));
			(l % 2 == 0) ? my_strcpy(f->len, "ll") : my_strcpy(f->len, "l\0");
		}
		else if (f->len[0] == 'h')
		{
			ft_memset(f->len, '\0', ft_strlen(f->len));
			(h % 2 == 0) ? my_strcpy(f->len, "hh") : my_strcpy(f->len, "h");
		}
	}
	if (f->flag == 1)
	{
		l = 0;
		h = 0;
	}
}

static void	find_conv(t_struct *form, char *s1)
{
	char s[4] = "hlzj";

	if ((*s1 == 'h' || *s1 == 'l' || *s1 == 'z' || *s1 == 'j')
		&& form->len[0] == '\0')
	{
		form->len[0] = *s1;
		if ((*s1 == 'l' && *(s1 + 1) == 'l') || (*s1 == 'h' && *(s1 + 1) == 'h'))
			form->len[1] = *(s1++);
	}
	else if (*s1 == 'h' || *s1 == 'l' || *s1 == 'z' || *s1 == 'j')
	{
		if (ft_strchr(s, *s1) > ft_strchr(s, form->len[0]))
		{
			form->len[0] = *s1;
			form->len[1] = '\0';
			if ((*s1 == 'l' && *(s1 + 1) == 'l') || (*s1 == 'h' && *(s1 + 1) == 'h'))
				form->len[1] = *(s1++);
		}
	}
	else //if ((*s1 >= 'A' && *s1 <= 'Z') || (*s1 >= 'a' && *s1 <= 'z') || *s1 == '%')
	{
		form->flag = 1;
		form->conv = *s1;
	}

}

int			to_struct(va_list argp, char **s, int b)
{
	char 			*s1;
	t_struct 		*form;
	int 			i;
	
	s1 = *s;
	i = 0;
	form = (t_struct *)malloc(sizeof(t_struct));
	init_struct(form);
    while (!form->flag && *s1 != '\0')
	{
		ll_hh(*s1,form);
		if (find_letter("+- #0", *s1))
			flags_to_struct(form, *s1, *(s1 - 1));
		else if ((*s1 >= '1' && *s1 <= '9') || *s1 == '*' 
			|| ((*s1 == '.') && ((*(s1 + 1) >= '0' && *(s1 + 1) <= '9') || *(s1 + 1) == '*')))
			s1 = digit_to_struct(form, s1, argp);
		else if (*s1 == '.' && !ft_isdigit(*(s1 + 1)))
			form->p = 0;
		else 
			find_conv(form, s1);
		s1++;
	}
	ll_hh(*s1, form);
    form->flag = b;
//printf("typedef struct format\n{\n	int plus =[%d]\n	int minus = [%d];\n	int sharp = [%d];\n	int space = [%d];\n	int zero = [%d];\n	int min =[%d]\n	int p = [%d]\n	char *length = [%s]\n	char conv = [%c]\n}\n",form->plus,form->minus,form->sharp,form->space,form->zero, form->min, form->p, form->len,form->conv);
	*s = s1 - 1;
//printf("typedef struct format\n{\n	int plus =[%d]\n	int minus = [%d];\n	int sharp = [%d];\n	int space = [%d];\n	int zero = [%d];\n	int min =[%d]\n	int p = [%d]\n	char *length = [%s]\n	char conv = [%c]\n}\n",form->plus,form->minus,form->sharp,form->space,form->zero, form->min, form->p, form->len,form->conv);
	i = handle_output(argp, form);
	free(form);
	return (i);
}
