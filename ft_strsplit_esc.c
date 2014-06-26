/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_esc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:44:38 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:44:39 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strsub_esc(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * len + 1);
	while (start < len)
	{
		if (s[start] != '\\')
		{
			str[i] = s[start];
			i++;
		}
		start++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_count_word_esc(char const *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		while (s[j] && s[j] == c && *(s - 1) != '\\')
			j++;
		while (s[j] && (s[j] != c || (s[j] == c && s[j - 1] == '\\')))
			j++;
		if (s[j] != '\0' || s[j - 1] != c || (s[j] == c && *(s - 1) == '\\'))
			i++;
	}
	return (i);
}

char		**ft_strsplit_esc(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_count_word_esc(s, c);
	str = (char **)malloc(sizeof(char *) * l + 1);
	while (i < l)
	{
		j = 0;
		while (*s && *s == c && *(s - 1) != '\\')
			s = s + 1;
		while (*(s + j) && (*(s + j) != c
			|| (*(s + j) == c && *(s + j - 1) == '\\')))
			j++;
		*(str++) = ft_strsub_esc(s, 0, j);
		s = s + j;
		i++;
	}
	*str = NULL;
	return (str - l);
}
