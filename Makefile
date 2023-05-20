# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djoyke <djoyke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/20 15:38:33 by djoyke        #+#    #+#                  #
#    Updated: 2023/05/20 16:07:52 by djoyke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME	= fractol
LIBFT	= ./Libft/libft.a
MLX42	= ./MLX42/build/libmlx42.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -Ofast -O3
LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include 
INCL	= -framework Cocoa -framework OpenGL -framework IOKit -lglfw
GLFW	= -L "`brew --prefix glfw`/lib/" -lglfw
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm $(INCL)
LIBS	+= $(GLFW)
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

$(NAME): $(LIBFT) $(OBJ) $(MLX42)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME) $(LIBS) $(HEADERS) 

$(MLX42):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

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
