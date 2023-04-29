/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:38:00 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 15:15:06 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
copy and concatenate strings 
They are designed to be safer, more consistent, 
and less error prone replacements for the easily misused functions

take the full size of the destination buffer 
and guarantee NUL-termination if there is room.  
Note that room for the NUL should be included in dstsize.

copies up to dstsize - 1 characters from the string src to dst, 
NUL-terminating the result if dstsize is not 0.

appends string src to the end of dst.  
It will append at most dstsize - strlen(dst) - 1 characters.  
It will then NUL-terminate, unless dstsize is 0 
or the original dst string was longer than dstsize 
(in practice this should not happen as it

RETURN
functions return the total length of the string they tried to create.  
For strlcpy() that means the length of src.

If the return value is >= dstsize, the output string has been truncated.  
It is the caller's responsibility to handle this.

size_t kan niet negatief zijn dus (i +1) ipv (destsize -1)

int main(void)
{
	char src[] = "hello";
	char dest[20];
	
	printf("%zu\n", ft_strlcpy(dest, src, 5));
	printf("%zu\n", strlcpy(dest, src, 5));
}
*/
