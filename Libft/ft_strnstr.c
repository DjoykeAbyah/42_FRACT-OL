/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:40:10 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 13:49:27 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
	{
		return ((char *)haystack);
	}
	while ((haystack[i] != '\0') && (i < len))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (j + i < len))
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
locates the first occurrence of the null-terminated 
string needle in the string haystack, 
where not more than len characters are searched.  
Characters that appear after a `\0' character are not searched.  

in a while loop be sure to write all the conditions 
even if you already wrote them in another loop

RETURN
If needle is an empty string, haystack is returned; 
if needle occurs nowhere in haystack, NULL is returned; 
otherwise a pointer to the first character 
of the first occurrence of needle is returned.
*/