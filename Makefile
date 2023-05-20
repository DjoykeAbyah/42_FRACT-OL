# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djoyke <djoyke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/20 15:38:33 by djoyke        #+#    #+#                  #
#    Updated: 2023/05/20 20:25:17 by djoyke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
LIBFT	= ./LIBFT/libft.a
MLX42	= ./MLX42/build/libmlx42.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -Ofast -O3
LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include
ifeq ($(shell uname -m),arm64)
INCL	= -framework Cocoa -framework OpenGL -framework IOKit -L "`brew --prefix glfw`/lib/" -lglfw
else ifeq ($(shell uname -m),x86_64)
INCL	= -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
endif
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm $(INCL)
SRC		= \
		main.c \
		navigate.c \
		atod.c \
		julia.c \
		mandelbrot.c \
		utils.c \

OBJ	= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

OBJDIR	= obj

all:	libmlx $(NAME)

# submodules:
# 	@git submodule update --init --recursive
# als je git submodule voor je MLX42 en LIBFT compiled git submodule update --init --recursive doet en dan de submodule command ertussenuit haalt moet het weer kloppen#

$(NAME): $(LIBFT) $(OBJ) $(MLX42)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME) $(LIBS) $(HEADERS) 

$(MLX42):
	@git submodule update --init --recursive
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

$(LIBFT):
		@git submodule update --init --recursive
		@$(MAKE) -C ./LIBFT

$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^ $(HEADERS)
		
$(OBJDIR)/%.o:
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		@$(MAKE) clean -C ./LIBFT
		@rm -rf $(OBJDIR)
		@rm -rf $(LIBMLX)/build

fclean: clean
		@$(MAKE) fclean -C ./LIBFT
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re libmlx
