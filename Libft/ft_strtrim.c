/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:11:04 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 15:20:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
	{
		start++;
	}
	if (len == 0 || start == len)
		len = 1;
	else
	{
		while (ft_strchr(set, s1[len - 1]) && len != 0)
			len--;
	}
	new_str = ft_substr(s1, start, len - start);
	return (new_str);
}

/* 
start + len is einde string
if s1 + i

Parameters:
1) s1: The string to be trimmed.
2) set: The reference set of characters to trim.

Return value:
The trimmed string.
NULL if the allocation fails.

External functs: 
malloc

Description: 
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.

1) wat is de set
2) wat is str to be trimmed.
3) reduce from start until no more part of the set
4) reduce from end until no more part of the set
5) use strchr and strrchr?
6) malloc while substr?
7) locatie opslaan van laatste occurence set +1? bij start
8) locatie opslaan van laatste occurense set -1 van end
*/