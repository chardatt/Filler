/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:26:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/01 17:08:17 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

	// 1:ajouter \n et on aura la map pure
	// 2: virer la première ligne et les 4 premiers caractères

t_data	*read_map(t_data *data)
{
	char	**ret;
	int		j;
	int		i;

	data->x = 0;
	i = 0;
	j = 0;
	if (!(ret = malloc(sizeof(char**) * data->height + 1)))
		return (NULL);
//	ret[data->height + 1] = "\0";
	while (ft_get_next_line(0, &data->line) == 1 && j <= data->height)
	{
		if (j > 0)
			if (!(ret[j - 1] = malloc(sizeof(char*) * data->width)))
				return (NULL);
		i = 4;
		data->x = 0;
		while (j >= 1 && data->line[i])
		{
			ret[j - 1][data->x] = data->line[i];
			data->x++;
			i++;
		}
		j++;
	}
//	ft_printtab(ret);
	data->map = ret;
	ft_putnbr_fd(j, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	return (data);
}
