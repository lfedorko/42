/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:35:12 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/05 18:13:37 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *mlist;
	t_list *tmp;

	if (alst != NULL && *alst != NULL)
	{
		mlist = *alst;
		while (mlist != NULL)
		{
			tmp = mlist;
			ft_lstdelone(&mlist, (*del));
			mlist = tmp->next;
		}
		*alst = NULL;
	}
}
