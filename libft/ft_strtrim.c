/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:13:50 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/02 16:10:08 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		b;
	int		size;
	int		k;
	char	*s1;
	int		c;

	c = 0;
	if (s == NULL)
		return (NULL);
	b = 0;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	k = b;
	if (s[b] == '\0')
		return (ft_strnew(0));
	b = ft_strlen(s) - 1;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b--;
	size = b - k + 2;
	if ((s1 = (char *)malloc(size * sizeof(char))) == NULL)
		return (0);
	while (k <= b)
		s1[c++] = s[k++];
	s1[c] = '\0';
	return (s1);
}
