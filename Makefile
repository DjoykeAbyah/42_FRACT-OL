# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djoyke <djoyke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/28 13:25:16 by djoyke        #+#    #+#                  #
#    Updated: 2023/04/28 17:37:58 by djoyke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
LIBFT	= ./libft/libft.a
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g
SRC	= 

OBJ	= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

OBJDIR	= obj

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): 
		@$(MAKE) -C ./libft

$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/%.o:
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJDIR)

fclean: clean
		@$(MAKE) fclean -C ./libft
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re