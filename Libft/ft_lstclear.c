/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:13:10 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/17 15:13:13 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_lst;

	while (*lst)
	{
		p_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p_lst;
	}
	*lst = NULL;
}

/*
Parameters: 
lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.

Return value: 
None

External functs:
free

Description:
1) Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
2) Finally, the pointer to the list must be set to
NULL.
*/