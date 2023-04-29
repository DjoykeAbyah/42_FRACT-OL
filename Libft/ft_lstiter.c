/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:13:36 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/17 15:13:40 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		f(temp->content);
		lst = lst->next;
	}
}

/*
Parameters:
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.

Return value:
None

Description:
Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
*/