/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:22:51 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 15:58:28 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*
The isalpha() function tests for any character for which isupper(3)
or islower(3) is true.
The value of the argument must be representable as an unsigned char or the
value of EOF.

The function returns zero if the character
tests false and returns non-zero if the character tests true.
*/

/*int	main(void)
{
	printf("%i\n", ft_isalpha('f'));
	printf("%i\n", isalpha('f'));
}*/
