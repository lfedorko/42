/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:57:03 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/08 13:14:52 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	leng;

	if (*lit == '\0')
		return ((char *)big);
	leng = ft_strlen(lit);
	while (len != 0 && *big != '\0')
	{
		if (*big == *lit)
		{
			if (len >= leng)
			{
				if (ft_strncmp(big, lit, leng) == 0)
					return ((char *)big);
			}
		}
		big++;
		len--;
	}
	return (NULL);
}
