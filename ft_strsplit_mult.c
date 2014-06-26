/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:50:55 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:50:56 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char			*ft_strsubb(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * len + 1);
	while (start < len)
	{
		*str = s[start];
		start++;
		str = str + 1;
	}
	*str = '\0';
	return (str - len);
}

static void			ft_count_word2(char const *s, char *c, int *i, int k)
{
	k = 0;
	while (s[*i] && c[k])
	{
		if (s[*i] == c[k])
		{
			*i = *i + 1;
			k = 0;
		}
		else
			k++;
	}
	k = 0;
	while (s[*i] && c[k])
	{
		while (c[k] && s[*i] != c[k])
			k++;
		if (c[k] == '\0')
		{
			k = 0;
			*i = *i + 1;
		}
		else
			break ;
	}
}

static int			ft_count_word(char const *s, char *c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		ft_count_word2(s, c, &i, k);
		k = 0;
		if (s[i] != '\0')
			j++;
		else
		{
			while (c[k] && s[i - 1] != c[k])
			{
				if (c[k + 1] == '\0')
					j++;
				k++;
			}
		}
	}
	return (j);
}

static char const	*ft_strsplit2(char const *s, char *c, int k, int *j)
{
	k = 0;
	while (*s && c[k])
	{
		if (*s == c[k])
		{
			k = 0;
			s = s + 1;
		}
		else
			k++;
	}
	k = 0;
	while (*(s + *j) && c[k])
	{
		while (c[k] && *(s + *j) != c[k])
			k++;
		if (c[k] == '\0')
		{
			k = 0;
			*j = *j + 1;
		}
		else
			break ;
	}
	return (s);
}

char				**ft_strsplit_mult(char const *s, char *c)
{
	char	**str;
	int		i;
	int		j;
	int		l;
	int		k;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	l = ft_count_word(s, c);
	str = (char **)malloc(sizeof(char *) * l + 1);
	while (i < l)
	{
		k = 0;
		j = 0;
		s = ft_strsplit2(s, c, k, &j);
		*(str++) = ft_strsubb(s, 0, j);
		s = s + j;
		i++;
	}
	*str = NULL;
	return (str - l);
}
