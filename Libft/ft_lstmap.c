/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:14:08 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/17 15:14:10 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*mod_node;
	void	*new_content;

	new_lst = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		if (new_content == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		mod_node = ft_lstnew(new_content);
		if (mod_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, mod_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
Parameters:
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.

Return: 
value The new list.
NULL if the allocation fails.

External functs:
malloc, free

Description:
1) Iterates the list ’lst’ and applies the function
’f’ on the content of each node. 
2) Creates a new list resulting 
of the successive applications of
the function ’f’. 
3)The ’del’ function is used to
delete the content of a node if needed.
*/