/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:42:48 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:42:49 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[len1 + i] = s2[i];
		i++;
	}
	s1[len1 + i] = '\0';
	return (s1);
}
