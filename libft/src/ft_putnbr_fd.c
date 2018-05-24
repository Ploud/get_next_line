/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:44:09 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/12 18:55:15 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	int		k;
	int		a;

	k = 1;
	i = n;
	i = n < 0 ? -i : i;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (k <= (i / 10))
		k = k * 10;
	while (k >= 1)
	{
		a = i / k + 48;
		i = i % k;
		ft_putchar_fd(a, fd);
		k = k / 10;
	}
}
