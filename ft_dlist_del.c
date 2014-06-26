/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:34:21 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:34:22 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdel_head(t_dlist *list, void (*p_fct)(void **))
{
	t_dnew	*temp;

	temp = list->head;
	if (list != NULL && list->head != NULL)
	{
		if (list->head->next != NULL)
		{
			list->head = temp->next;
			temp->next->prev = NULL;
			temp->next = NULL;
		}
		else
		{
			list->head = NULL;
			list->tail = NULL;
		}
		(*p_fct)(&temp->data);
		free(temp);
		temp = NULL;
		list->size--;
	}
}

void	ft_dlst_del(t_dlist *list, size_t pos, void (*p_fct)(void **))
{
	t_dnew	*temp;
	size_t	i;

	i = 0;
	if (pos == 0)
		ft_dlstdel_head(list, p_fct);
	else if (pos == list->size - 1)
		ft_dlstdel_tail(list, p_fct);
	else
	{
		temp = list->head;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		(*p_fct)(&temp->data);
		free(temp);
		temp = NULL;
		list->size--;
	}
}

void	ft_dlstdel_tail(t_dlist *list, void (*p_fct)(void **))
{
	t_dnew	*temp;

	temp = list->tail;
	if (list != NULL && list->tail != NULL)
	{
		if (list->tail->prev != NULL)
		{
			list->tail = temp->prev;
			temp->prev->next = NULL;
			temp->prev = NULL;
		}
		else
		{
			list->head = NULL;
			list->tail = NULL;
		}
		(*p_fct)(&temp->data);
		free(temp);
		temp = NULL;
		list->size--;
	}
}

void	ft_dlstdel_all(t_dlist *list, void (*p_fct)(void **))
{
	t_dnew	*tmp;

	if (list != NULL && list->head != NULL)
	{
		while (list->head != NULL)
		{
			tmp = list->head;
			list->head = list->head->next;
			if (tmp != NULL)
			{
				(*p_fct)(&tmp->data);
				free(tmp);
				tmp = NULL;
				list->size--;
			}
		}
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	free(list);
	list = NULL;
}

void	ft_dlstdel_elem(t_dlist *list, void (*p_fct)(void **))
{
	t_dnew	*tmp;

	if (list != NULL && list->head != NULL)
	{
		while (list->head != NULL)
		{
			tmp = list->head;
			list->head = list->head->next;
			if (tmp != NULL)
			{
				(*p_fct)(&tmp->data);
				free(tmp);
				tmp = NULL;
				list->size--;
			}
		}
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
}
