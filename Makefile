NAME	= fractol
LIBFT	= ./Libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -Wunreachable-code 
LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include 
INCL	= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm $(INCL)
SRC		= \
		main.c \
		navigate.c \
		atod.c \
		julia.c \
		mandelbrot.c \

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