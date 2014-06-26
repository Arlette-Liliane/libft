/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_fct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:35:14 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:35:15 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_dlst_print(t_dlist *list)
{
	t_dnew	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		ft_putendl(temp->data);
		temp = temp->next;
	}
}

void	ft_dlst_print_sp(t_dlist *list)
{
	t_dnew	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		ft_putstr(temp->data);
		write(1, " ", 1);
		temp = temp->next;
	}
	write(1, "\n", 1);
}

void	ft_dlst_print_fd(t_dlist *list, int fd)
{
	t_dnew	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		ft_putendl_fd(temp->data, fd);
		temp = temp->next;
	}
}

void	ft_dlst_rprint(t_dlist *list)
{
	t_dnew	*temp;

	temp = list->tail;
	while (temp != NULL)
	{
		ft_putendl(temp->data);
		temp = temp->prev;
	}
}

void	ft_dlst_print_tab(t_dlist *list)
{
	t_dnew	*tmp;
	char	**tab;
	int		i;

	tmp = list->head;
	while (tmp != NULL)
	{
		i = -1;
		tab = tmp->data;
		while (tab[++i])
		{
			ft_putstr(tab[i]);
			if (tab[i + 1])
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
