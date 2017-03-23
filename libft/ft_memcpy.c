/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:58:39 by lfedorko          #+#    #+#             */
/*   Updated: 2016/11/28 12:02:07 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s2;
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)src;
	s1 = (unsigned char *)dst;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return ((void *)dst);
}
