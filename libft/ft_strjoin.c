/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:03:03 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/02 14:06:02 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (ft_strdup(s2));
	i = ft_strlen(s1) + ft_strlen(s2);
	con = (char *)malloc((i + 1) * sizeof(char));
	if (con == NULL)
		return (NULL);
	ft_strcpy(con, s1);
	ft_strcat(con, s2);
	return (con);
}
