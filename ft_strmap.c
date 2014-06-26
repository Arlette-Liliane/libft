/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:42:17 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:42:18 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s));
		if (s2 == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			s2[i] = f(s[i]);
			i++;
		}
		return (s2);
	}
	return (0);
}
