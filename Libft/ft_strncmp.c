/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:45:09 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 13:41:43 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n > i)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

/*
compares not more than n characters.  
Because strncmp() is designed for comparing strings rather than binary data, 
characters that appear after a `\0' character are not compared.

RETURN
functions return an integer greater than, equal to, or less than 0, 
according as the string s1 is greater than, equal to, 
or less than the string s2.  
The comparison is done using unsigned characters, 
so that `\200' is greater than `\0'.
*/