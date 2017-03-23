#include "ft_printf.h"

static int	count_w(wchar_t c, t_struct *form)
{
	form->space = 0;
    form->plus = 0;
    form->p = -1;
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


char 		*ft_widechar(void *c, t_struct *form)
{
	int		size;
	int 	key;
	char	*s;
	wchar_t i;

	i = (wchar_t)c;
	if ((int)i == 0)
		return (ft_c(form, (char)i));
	size = count_w(i, form);
	s = ft_strnew(size);
	if (size == 4)
		key = 240;
	if (size == 3)
		key = 224;
	if (size == 2)
		key = 192;
	if (size == 1)
		*s = i;
	else
		s[0] = ((i >> (6 * (size - 1))) | key);
	while (size > 1)
	{
		s[size - 1] = ((63 & i) | 128);
		i = i >> 6;
		size--;
	}
	return (s);
}
