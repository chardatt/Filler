/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:40:14 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/13 21:40:15 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	if ((char)c == '\0')
		return ((char *)s);
	s--;
	while (*s != (char)c && *s)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
