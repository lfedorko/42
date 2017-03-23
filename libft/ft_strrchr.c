/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:29:37 by lfedorko          #+#    #+#             */
/*   Updated: 2016/11/25 17:40:49 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!ft_strchr(s, c))
		return (NULL);
	while (s[i] != '\0')
		i++;
	while (s[i] != c)
		i--;
	return ((char *)(&s[i]));
}
