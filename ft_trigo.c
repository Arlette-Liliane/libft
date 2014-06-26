/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:47:09 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:47:10 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_check_angle(float angle)
{
	while (angle > 360 || angle < -360)
	{
		if (angle > 360)
			angle -= 360;
		else
			angle += 360;
	}
	if (angle > 180)
		angle -= 360;
	else if (angle < -180)
		angle += 360;
	return (angle);
}

float	ft_cos(float angle)
{
	float	result;
	int		n;
	float	angle2;

	angle = ft_check_angle(angle);
	angle2 = angle * 3.14 / 180;
	n = 1;
	result = 1;
	while (n < 5)
	{
		result += ft_power(-1, n) * ((ft_power(angle2, n + n)
										/ ft_facto(n + n)));
		n++;
	}
	if (result > 1)
		return (1);
	if (result < -1)
		return (-1);
	return (result);
}

float	ft_sin(float angle)
{
	float	result;
	int		n;
	float	angle2;

	angle = ft_check_angle(angle);
	n = 1;
	angle2 = angle * 3.14 / 180;
	result = angle2;
	while (n < 5)
	{
		result += ft_power(-1, n) * ((ft_power(angle2, n + n + 1)
										/ ft_facto(n + n + 1)));
		n++;
	}
	if (result > 1)
		return (1);
	if (result < -1)
		return (-1);
	return (result);
}

float	ft_tan(float angle)
{
	return (ft_sin(angle) / ft_cos(angle));
}
