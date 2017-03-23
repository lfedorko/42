/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:40:06 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:40:08 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	itoa_size(uintmax_t c, int base, int h, char letter)
{
	int count;

	count = 0;
	if (c == 0 && letter != 'p')
		return (1);
	if (letter == 'p' && c == 0)
		return (3);
	while (c != 0)
	{
		c /= base;
		count++;
	}
	if (h == 1)
	{
		if (letter == 'o' || letter == 'O')
			return (count + 1);
		else if (find_letter("pXx", letter))
			return (count + 2);
		return (count);
	}
	return (count);
}

static void	itoa_base2(int count, char *str, uintmax_t value, int *flags)
{
	int resudial;

	while (count >= 0)
	{
		resudial = value % flags[1];
		if (resudial > 9)
		{
			if (flags[0] == 'x' || flags[0] == 'p')
				resudial += 39;
			else
				resudial += 7;
		}
		value = value / flags[1];
		str[count] = resudial + 48;
		count--;
	}
}

static int	flags1(char **str, int letter, int count)
{
	if (find_letter("pXx", letter))
	{
		**str = '0';
		*str = *str + 1;
		if (letter == 'x' || letter == 'p')
			**str = 'x';
		else
			**str = 'X';
		*str = *str + 1;
		return (count - 2);
	}
	else if (letter == 'o' || letter == 'O')
	{
		**str = '0';
		*str = *str + 1;
		return (count - 1);
	}
	return (count);
}

char		*itoa_base(uintmax_t value, int base, char letter, int h)
{
	char	*str;
	int		count;
	int		flags[2];

	flags[0] = letter;
	flags[1] = base;
	count = itoa_size(value, base, h, letter);
	str = (char *)malloc((count + 1) * sizeof(char));
	str[count] = '\0';
	count--;
	if (h == 1 && (value != 0 || letter == 'p'))
	{
		count = flags1(&str, letter, count);
		itoa_base2(count, str, value, flags);
		if (letter == 'o' || letter == 'O')
			return (str - 1);
		else if (find_letter("pXx", letter))
			return (str - 2);
		return (str);
	}
	itoa_base2(count, str, value, flags);
	return (str);
}
