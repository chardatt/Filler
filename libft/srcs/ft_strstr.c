/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:40:35 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/13 21:40:36 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(&big[i]));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
