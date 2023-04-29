/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:32:12 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 13:52:34 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;
	int		len;

	d = (char *)s;
	len = ft_strlen(d);
	while (len >= 0)
	{
		if (d[len] == (char)c)
		{
			return (&d[len]);
		}
		len--;
	}
	return (NULL);
}

/*
function is identical to strchr(), except it locates the last occurrence of c.

the functions strchr() and strrchr() return a pointer to the located character, 
or NULL if the character does not appear in the string.
*/