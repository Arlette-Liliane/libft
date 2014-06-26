/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:44:53 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:44:54 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_str2(const char *s1, const char *s2, int i)
{
	int		k;
	int		j;

	k = i;
	j = 0;
	while (s2[j] == s1[k] && s1[k] != '\0' && s2[j] != '\0')
	{
		k++;
		j++;
		if (s2[j] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s2[0] == s1[i])
		{
			if (ft_str2(s1, s2, i) == 1)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
