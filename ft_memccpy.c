/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:36:03 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:36:05 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == c)
			return (str1 + i + 1);
		i++;
	}
	return (0);
}
