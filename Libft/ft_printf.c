/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:16:27 by dreijans      #+#    #+#                 */
/*   Updated: 2023/03/28 15:07:25 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(va_list arg, char s)
{
	if (s == 'c')
		return (print_char(va_arg(arg, unsigned int)));
	else if (s == 's')
		return (print_str(va_arg(arg, char *)));
	else if (s == 'd' || s == 'i')
		return (print_nbr(va_arg(arg, int)));
	else if (s == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	else if (s == 'x')
		return (print_hexlow(va_arg(arg, unsigned int)));
	else if (s == 'X')
		return (print_hexup(va_arg(arg, unsigned int)));
	else if (s == '%')
		return (print_char('%'));
	else if (s == 'p')
		return (print_ptr(va_arg(arg, unsigned long int)));
	return (-1);
}

static int	check_minus(const char *format, va_list arg)
{
	int			count;
	int			nbr;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format++ + 1) != '\0')
		{
			nbr = check_format(arg, *format);
			if (nbr == -1)
				return (-1);
			count = count + nbr;
		}
		else
		{
			if (*format != '%')
			{
				if (print_char(*format) == -1)
					return (-1);
				count++;
			}
		}
	format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		arg;

	va_start(arg, format);
	count = check_minus(format, arg);
	if (count == -1)
		return (-1);
	va_end (arg);
	return (count);
}

/*
Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository

  %c Prints a single character. X
• %s Prints a string (as defined by the common C convention). X
• %p The void * pointer argument has to be printed in hexadecimal *format. X
• %d Prints a decimal (base 10) number. X
• %i Prints an integer in base 10. X
• %u Prints an unsigned decimal (base 10) number. X
• %x Prints a number in hexadecimal (base 16) lowercase *format. X
• %X Prints a number in hexadecimal (base 16) uppercase *format. X
• %% Prints a percent sign. X

va_start function
is a macro defined 
in the stdarg header file in the C Programming languages. 
The va_start() function is used to initialize the argument list. 
The argument list is referred to by ap. 
Initializing the argument list is necessary 
before using the va_arg() and va_end() functions in the program

va_list
is a complete object type suitable for holding 
the information needed by the macros va_start, 
va_copy, va_arg, and va_end. 
If a va_list instance is created, 
passed to another function, 
and used via va_arg in that function, 
then any subsequent use in the calling 
function should be preceded by a call to va_end

va_arg function 
fetches an argument in a variable argument list.
The va_arg function updates ap so that 
the next call to the va_arg function fetches the next argument. 
You must call the va_start function 
to initialize ap before using the va_arg function

va_end function(va_list ap) 
allows a function with variable arguments 
which used the va_start macro to return. 
If va_end is not called before returning from the function, 
the result is undefined.
ap − This is the va_list object previously 
initialized by va_start in the same function.

ar -tv libftprintf.a checks .a file!
*/
