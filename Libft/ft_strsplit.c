/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:14:05 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/19 18:56:17 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compte_lettres(char const *str, char c)
{
	int i;

	i = 0;
	while (!(str[i] == c) && str[i])
	{
		i++;
	}
	return (i);
}

static int	compte_mots(char const *str, char c)
{
	int i;
	int nbr_mot;

	i = 0;
	nbr_mot = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			nbr_mot++;
		while (!(str[i] == c) && str[i])
			i++;
	}
	return (nbr_mot);
}

static int	remplir(char **tab, char c, int j, char const *str)
{
	int		k;
	char	*truc;

	while (str[j] == c)
		j++;
	if (!(truc = malloc(sizeof(char) * (compte_lettres(str + j, c) + 1))))
		return (-1);
	k = 0;
	while (!(str[j] == c) && str[j])
		truc[k++] = str[j++];
	truc[k] = '\0';
	*tab = truc;
	return (j);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	nb = compte_mots(str, c);
	if (!(tab = malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	tab[nb] = 0;
	while (i < nb)
	{
		if ((j = remplir(&tab[i], c, j, str)) == -1)
			return (NULL);
		i++;
	}
	return (tab);
}
