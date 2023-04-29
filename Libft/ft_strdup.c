/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 12:09:38 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/02 17:29:51 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*s2;

	len = ft_strlen(s1)+1;
	s2 = malloc(len * sizeof (char));
	if (s2 == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s2, (void *)s1, len);
	return (s2);
}

/*
function allocates sufficient memory 
1)for a copy of the string s1,
2)does the copy 
3)and returns a pointer to it.

The pointer may subsequently be used as an argument to the function free(3).
If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
free(3), malloc(3)
return char pointer
*/