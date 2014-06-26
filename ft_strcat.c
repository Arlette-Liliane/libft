/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:39:21 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:39:22 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		len1;

	i = 0;
	if (s2 == NULL)
		return (s1);
	len1 = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len1 + i] = s2[i];
		i++;
	}
	s1[len1 + i] = '\0';
	return (s1);
}
