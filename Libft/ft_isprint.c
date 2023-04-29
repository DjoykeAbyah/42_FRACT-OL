/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 10:46:19 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 15:59:12 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/*
tests for any printing character, including space (` ').  
The value of the argument must be representable as an unsigned char or the
value of EOF.
*/