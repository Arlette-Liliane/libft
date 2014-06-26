/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_carac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:46:32 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:46:33 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim_carac(char const *s, char c)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (0);
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[j] == c || s[j] == '\0')
		j--;
	while (i <= j)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
