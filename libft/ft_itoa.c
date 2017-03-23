/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:09:40 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/07 13:43:14 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int c)
{
	int			count;

	count = 0;
	if (c == 0 || c < 0)
		count++;
	while (c != 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			count;
	int			i;
	long		num;

	i = 0;
	num = n;
	count = ft_size(num);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[i++] = '-';
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
