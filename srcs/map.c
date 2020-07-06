/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:26:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/07/06 19:29:55 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data	*read_map(t_data *data)
{
	char	**ret;
	int		j;
	int		i;

	data->x = 0;
	i = 0;
	j = 0;
	if (data->first == 1)
		ft_get_next_line(0, &data->line);
	if (!(ret = malloc(sizeof(char**) * data->height + 1)))
		return (NULL);
	while (ft_get_next_line(0, &data->line) == 1 && j <= data->height)
	{
		if (j > 0)
			if (!(ret[j - 1] = malloc(sizeof(char*) * data->width)))
				return (NULL);
		i = 3;
		data->x = 0;
		while (j >= 1 && data->line[i++])
			ret[j - 1][data->x++] = data->line[i];
		j++;
	}
	data->map = ret;
	return (data);
}
