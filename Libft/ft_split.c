/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 19:34:23 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/02 20:25:48 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lencount(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	wordcount(char const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

static char	**freedom(char **md_array)
{
	int	i;

	i = 0;
	while (md_array[i] != NULL)
	{
		free(md_array[i]);
		i++;
	}
	free(md_array);
	return (NULL);
}

static char	*fill(char const *s, char c, int *i)
{
	char	*str;
	char	*d;
	int		len;

	d = (char *)s;
	len = lencount(d, c);
	str = ft_substr(d, 0, len);
	if (str == 0)
	{
		return (0);
	}
	*i += len;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	split_str = (char **)malloc((sizeof(char *) * (wordcount(s, c) + 1)));
	if (split_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		split_str[j] = fill(&s[i], c, &i);
		if (split_str[j] == NULL)
			return (freedom(split_str));
			j++;
	}
	split_str[j] = NULL;
	return (split_str);
}

/*
Parameters:
s: The string to be split.
c: The delimiter character.

Return value: 
The array of new strings resulting from the split.
NULL if the allocation fails.

External functs: 
malloc, 
free

Description: 
Allocates (with malloc(3)) 
returns an array of strings obtained by splitting s
using the character ’c’ as a delimiter. 
The array must end with a NULL pointer.

extra function messes with value of i and j.
uses pointers to change value not the addres
break prevents from accessing unallocated memory
stops the loop
*/