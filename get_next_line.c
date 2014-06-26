/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:47:20 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:47:21 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		ft_strisntnull(char **line, char **str)
{
	*line = ft_strdup(*str);
	ft_strdel(str);
	return (1);
}

static int		ft_linelength(char **line, char **str, int n)
{
	n = ft_strchr(*str, '\n') - *str;
	*line = ft_strsub(*str, 0, n);
	*str = ft_strsub(*str, n + 1, ft_strlen(*str) - n - 1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			n;
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*str = NULL;

	n = 0;
	while (str == NULL || ft_strchr(str, '\n') == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (ret < 0)
			return (-1);
		if (ret == 0)
		{
			if (str != NULL)
				return (ft_strisntnull(line, &str));
			return (0);
		}
		if (str != NULL)
			str = ft_strjoin(str, buff);
		else
			str = ft_strdup(buff);
	}
	return (ft_linelength(line, &str, n));
}
