/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:34:39 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 13:35:31 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*d;

	d = (char *)s;
	while (*d != '\0')
	{
		if (*d == (char) c)
		{
			return (d);
		}
		d++;
	}
	if ((char) c == '\0')
	{
		return (d);
	}	
	return (NULL);
}

/*
locates the first occurrence of c (converted to a char)
in the string pointed to by s.
The terminating null character is considered to be part of the string; 
therefore if c is `\0', the functions locate the terminating `\0'.

return a pointer to the located character
or NULL if the character does not appear in the string.
*/