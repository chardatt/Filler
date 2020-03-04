/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_empty_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:22:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/03/04 10:05:16 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_empty_column(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
	{
		if (tab[y][0] == '*')
			return (-1);
		y++;
	}
	return (0);
}

char	*ft_suppr_char(char *str, int j)
{
	int i;
	char *str_ret;

	i = 0;
	if (!(str_ret = ft_strnew(ft_strlen(str) - j)))
		return (NULL);
	while (str[j])
	{
		str_ret[i] = str[j];
		j++;
		i++;
	}
	ft_strdel(&str);
	return (str_ret);
}

char	**ft_sort_empty_column(char **tab)
{
	int y;

	y = 0;
	if (ft_check_empty_column(tab) == 0)
	{
		while (tab[y])
		{
			tab[y] = ft_suppr_char(tab[y], 0);
			y++;
		}
	}
	return (tab);
}
