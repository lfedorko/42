/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:09:03 by lfedorko          #+#    #+#             */
/*   Updated: 2016/11/30 18:23:33 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	if (s != NULL)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			s[i] = '\0';
			i--;
		}
	}
}
