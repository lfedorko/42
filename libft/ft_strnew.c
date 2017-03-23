/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:09:52 by lfedorko          #+#    #+#             */
/*   Updated: 2016/11/28 17:05:57 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = ((char *)malloc((size + 1) * sizeof(char)));
	if (s1 == NULL)
		return (NULL);
	while (size + 1 != 0)
	{
		s1[i] = '\0';
		i++;
		size--;
	}
	return (s1);
}
