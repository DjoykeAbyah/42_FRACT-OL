/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:12:38 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/17 15:12:42 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst)
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
	else
	{
		*lst = new;
	}
}

/*
Parameters:
lst: The address of a pointer
to the first link of a list.
new: The address of a pointer
to the node to be added to the list.

Description:
Adds the node ’new’ at the end of the list.
*/