NAME = fractol

SOURCE = ./source/

LIBFT_A = ./libft/

COMPILER = cc -g -Wall -Wextra -Werror

MINILIBX_ARGS = -lXext -lX11 -lm

GET_SOURCES = $(shell find $(SOURCE))

FILTER_SOURCES = $(filter %.c, $(GET_SOURCES))

OBJS = $(FILTER_SOURCES:%.c=%.o)

MINILIBX_A = minilibx/libmlx.a

LIBFT_A = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(MINILIBX_A) $(OBJS)
	$(COMPILER) $(OBJS) $(MINILIBX_A) $(MINILIBX_ARGS) $(LIBFT_A) -o $(NAME)

.c.o:
	$(COMPILER) -c $< -o $@ -I ./includes/

$(LIBFT_A):
	cd libft/ && make && cd ..

$(MINILIBX_A):
	cd minilibx/ && make && cd ..

clean:
	rm -f $(OBJS)
	cd libft && make clean && cd ..
	cd minilibx/ && make clean && cd ..

fclean: clean
	rm -f $(NAME) $(LIBFT_A) $(MINILIBX_A)

re: fclean all

.PHONY: all object clean fclean re
