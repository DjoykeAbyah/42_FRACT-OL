/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:40:14 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 16:39:03 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*
function tests for a decimal digit character.
function returns zero if the character tests false
and return non-zero if the character tests true.
*/

/*
int	main(void)
{
	printf("%i\n", ft_isdigit('9'));
	printf("%i\n", isdigit('2'));
}
*/
