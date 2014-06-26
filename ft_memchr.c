/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:36:16 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:36:17 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str1;
	size_t			i;

	str1 = (unsigned char *)s;
	i = 0;
	if (str1 == NULL)
		return (0);
	while (i < n && str1[i] != '\0' && str1[i] != c)
		i++;
	if (str1[i] == c)
		return (str1 + i);
	else
		return (0);
}
