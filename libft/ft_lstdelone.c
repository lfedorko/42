/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:12:39 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/05 18:14:22 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *dellst;

	if (alst != NULL && *alst != NULL)
	{
		dellst = *alst;
		(*del)(dellst->content, dellst->content_size);
		free(dellst);
		*alst = NULL;
	}
}
