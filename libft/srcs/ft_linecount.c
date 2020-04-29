/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:30:46 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/13 21:30:48 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_linecount(char *str)
{
	int		lines;

	lines = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines);
}
