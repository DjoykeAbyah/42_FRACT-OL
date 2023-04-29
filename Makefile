# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djoyke <djoyke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/28 13:25:16 by djoyke        #+#    #+#                  #
#    Updated: 2023/04/29 17:14:53 by djoyke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
LIBFT	= ./libft/libft.a
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -Wunreachable-code 
LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include 
LDFLAGS = -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm $(LDFLAGS)
SRC	= main.c

OBJ	= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

OBJDIR	= obj

all:	libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS) $(HEADERS)

$(LIBFT): 
		@$(MAKE) -C ./libft

$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^ $(HEADERS)

$(OBJDIR)/%.o:
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJDIR)
		@rm -rf $(LIBMLX)/build

fclean: clean
		@$(MAKE) fclean -C ./libft
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re libmlx