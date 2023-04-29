/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:19:08 by dreijans      #+#    #+#                 */
/*   Updated: 2023/04/07 19:15:18 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	size_t		len;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = (char *)malloc(sizeof (char) * len);
	if (new_str != NULL)
	{
		ft_strlcpy(new_str, s1, (ft_strlen(s1) + 1));
		ft_strlcat(new_str, s2, len);
		return (new_str);
	}
	return (NULL);
}

/*
Parameters:
1) s1: The prefix string.
2) s2: The suffix string.

Return value: 
The new string.
NULL if the allocation fails.

External functs: 
malloc

Description: 
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/