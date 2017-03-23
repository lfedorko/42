/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:59:34 by lfedorko          #+#    #+#             */
/*   Updated: 2016/11/28 13:13:54 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		c;

	c = 0;
	i = ft_strlen(s1);
	res = (char *)malloc((i + 1) * sizeof(*res));
	if (res == NULL)
		return (NULL);
	while (s1[c] != '\0')
	{
		res[c] = s1[c];
		c++;
	}
	res[c] = '\0';
	return (res);
}
