/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:35:26 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:35:28 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_tab(char **tab)
{
	int		i;

	i = -1;
	if (tab == NULL)
	{
		free(tab);
		tab = NULL;
		return ;
	}
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
}
