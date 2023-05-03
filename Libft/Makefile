# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dreijans <dreijans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 16:56:00 by dreijans      #+#    #+#                  #
#    Updated: 2023/05/01 15:10:09 by dreijans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = \
ft_isalnum.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_strlcpy.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_atoi.c \
ft_strnstr.c \
ft_strlcat.c \
ft_memcpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_strtrim.c \
ft_striteri.c \
ft_strmapi.c \
ft_itoa.c \
ft_putnbr_fd.c \
ft_split.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstlast.c \
ft_lstsize.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_printf.c \
print_char.c \
print_hexlow.c \
print_hexup.c \
print_nbr.c \
print_ptr.c \
print_str.c \
print_unsigned.c

OBJ	= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

OBJDIR	= obj

all: $(NAME)
	
$(NAME): $(OBJ)
		ar -src $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/%.o:
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		$(RM) -rf $(OBJDIR)

fclean: 
		$(RM) -rf $(OBJDIR)
		$(RM) $(NAME)
		
re: fclean all

.PHONY: all clear fclean re
