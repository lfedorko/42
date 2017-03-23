/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:57:50 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/07 15:01:58 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;

	n1 = n;
	if (n < 0)
	{
		n1 = -n1;
		ft_putchar_fd('-', fd);
	}
	else
		n1 = n;
	if (n1 > 9)
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putnbr_fd(n1 % 10, fd);
	}
	else
		ft_putchar_fd(n1 + '0', fd);
}
