/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:52:15 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 13:53:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	size_t		strlen;

	strlen = ft_strlen((char *)s);
	if (start >= strlen)
		len = 0;
	else if (len > strlen - start)
		len = strlen - start;
	new_str = (char *)malloc((sizeof(char) * (len + 1)));
	if (new_str == NULL)
		return (NULL);
	if (strlen == 0 || len == 0)
		new_str[0] = 0;
	else
		ft_strlcpy(new_str, &s[start], len + 1);
	return (new_str);
}

/*
Parameters:
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Return value: 
The substring.
NULL if the allocation fails.

External functs.:
malloc

Description:
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

check conditions voor malloc anders malloc je teveel
als start groter is dan strlen valt er niks te kopieren, geef empty string.
als len groter is dan strlen wil je maar tot \0 kopieren dus strlen - start
if i set my len to 0 it doesnt make any sense to copy from 0 +start 
so i needed another exeption to set my newstr to zero without ft_strlcpy
and after malloc because i need the string to exist
*/