/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:27:32 by lfedorko          #+#    #+#             */
/*   Updated: 2017/03/23 12:27:37 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		compare(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		find_letter(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_realloc(char *s, int size)
{
	int		i;
	char	*s1;

	i = 0;
	if (ft_strlen(s) >= size)
		return (s);
	s1 = ft_strnew(size + 1);
	while (s[i] != '\0')
	{
		s1[i] = s[i];
		i++;
	}
	free(s);
	return (s1);
}

char	*record1(char *s, int i, int size)
{
	while (i > 0)
	{
		while (size > 0)
		{
			s[size + i - 1] = s[size - 1];
			size--;
		}
		s[i - 1] = '0';
		i--;
	}
	return (s);
}
