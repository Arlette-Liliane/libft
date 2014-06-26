/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:37:41 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:37:42 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_putint(int c)
{
	write(1, &c, 1);
	return (0);
}
