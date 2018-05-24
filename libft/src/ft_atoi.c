/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:31:35 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/12 19:00:20 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nb += str[i] - 48;
		if (nb == 214748364 && str[i + 1] == '8')
			return (-2147483648);
		if (str[i + 1] && '0' <= str[i + 1] && str[i + 1] <= '9')
			nb *= 10;
		i++;
	}
	return (nb * sign);
}
