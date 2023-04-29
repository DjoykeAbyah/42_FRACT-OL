/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 18:43:47 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 15:40:00 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	new_str = ft_strdup(s);
	if (new_str == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}

/*
Parameters:
s: The string on which to iterate.
f: The function to apply to each character.

Return value: 
The string created from the successive applications of ’f’.

Returns: 
NULL if the allocation fails.

External functs: 
malloc

Description:
1)Applies the function ’f’ to each character of the string ’s’,
2)passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/