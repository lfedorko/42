/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:01:41 by lfedorko          #+#    #+#             */
/*   Updated: 2016/11/28 11:48:13 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *s1;

	s1 = s;
	while (n > 0)
	{
		if (*s1 == (unsigned char)c)
			return ((void *)(s1));
		n--;
		s1++;
	}
	return (NULL);
}
