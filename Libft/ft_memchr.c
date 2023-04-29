/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 13:14:17 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 14:39:54 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

/* 
size_t It’s a type which is used to represent the size of objects in bytes
It is guaranteed to be big enough to contain the 
size of the biggest object the host system can handle. 
Basically the maximum permissible size is dependent on the compiler; 
if the compiler is 32 bit then it is simply a typedef(i.e., alias) 
for unsigned int but if the compiler is 64 bit 
then it would be a typedef for unsigned long long. 
The size_t data type is never negative.
uit index juiste adres geven niet gewoon pointer anders krijg je hele string

(1) find \0
(2) cast in unsigned memory
DO NOT OVERPROTECT OR PROTECT AT ALL BECAUSE ORIGINAL DOESNT EITHER

The memchr() 
(1)built-in function searches the first count bytes pointed to by buf 
(2)for the first occurrence of c 
(3)converted to an unsigned character. 
(4) The search continues until it finds c or examines count bytes.*/