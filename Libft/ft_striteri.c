/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:17:29 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 16:20:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
Parameters: 
s: The string on which to iterate.
f: The function to apply to each character.

Return value: 
None

External funct:
None

Description:
1)Applies the function ’f’ on each character of the string passed as argument, 
2)passing its index as first argument. 
3)Each character is passed by address to ’f’ to be modified if necessary.
just passing an int and a string, not dereferencing the f
needs to go through each character so at the address of the str 
not the pointer address and loop through the index to check.
*/