/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:38:12 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:38:13 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbrf2(float n, int i, int fd, int count)
{
	char	temp;
	int		div;

	div = 1;
	while (n - (int)n > 0.0)
		n = n * 10;
	while (n / div >= 10)
		div = div * 10;
	while (div > 0 && count <= 6)
	{
		temp = '0' + n / div;
		write(fd, &temp, 1);
		i = i / 10;
		if (i == 1)
			write(fd, ".", 1);
		count = (i <= 1) ? count + 1 : count;
		n = (int)n % div;
		div = div / 10;
	}
	while (count++ <= 6)
		write(1, "0", 1);
}

void		ft_putnbrf_fd(float n, int fd)
{
	int		count;
	int		div;
	int		i;

	count = 0;
	i = 1;
	div = 1;
	if (n < 0.0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 0.0 && n < 1.0)
	{
		count++;
		write(1, "0.", 2);
	}
	while (n / div >= 1)
	{
		div = div * 10;
		i = i * 10;
	}
	ft_putnbrf2(n, i, fd, count);
}

void		ft_putnbrf(float n)
{
	ft_putnbrf_fd(n, 1);
}
