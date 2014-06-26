/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:35:51 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:35:52 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_power(float nb, int power)
{
	float	result;
	int		i;

	result = nb;
	i = 1;
	if ((power < 0) || (nb == 0 && power > 0))
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

int		ft_facto(int nb)
{
	int		i;
	int		result;

	i = 0;
	result = nb;
	if (nb == 1 || nb == 0)
		return (1);
	if (nb >= 13 || nb < 0)
		return (-1);
	while (++i < nb)
		result *= (nb - i);
	return (result);
}

float	ft_rsqrt(float nb)
{
	float	result;
	float	i;

	if (nb == 0)
		return (0);
	i = 1;
	if (nb > 1)
	{
		while (nb - i * i > 0)
			i++;
		if (i * i - nb > nb - (i - 1) * (i - 1))
			result = i;
		else
			result = i - 1;
	}
	else
		result = 1;
	result = 0.5 * (result + nb / result);
	result = 0.5 * (result + nb / result);
	result = 0.5 * (result + nb / result);
	return (result);
}
