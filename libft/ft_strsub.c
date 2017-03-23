/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:27 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/03 15:38:42 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s1 = (char *)malloc((len + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	while (len != 0 && s[start] != '\0')
	{
		s1[i++] = s[start++];
		len--;
	}
	s1[i] = '\0';
	return (s1);
}
