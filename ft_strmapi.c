/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:42:31 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:42:32 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s));
		if (s2 == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		return (s2);
	}
	return (0);
}
