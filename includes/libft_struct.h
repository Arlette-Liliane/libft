/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:47:54 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:47:55 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCT_H
# define LIBFT_STRUCT_H

typedef struct			s_list_dnew
{
	void				*data;
	struct s_list_dnew	*prev;
	struct s_list_dnew	*next;
}						t_dnew;

typedef struct			s_dlist
{
	size_t				size;
	t_dnew				*head;
	t_dnew				*tail;
}						t_dlist;

#endif
