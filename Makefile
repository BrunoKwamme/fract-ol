NAME = push_swap

RM = rm -f
COMPILER = clang -g -Wall -Wextra -Werror
DIR_SRCS = source/
DIR_INCLUDES = includes/
LIBFT_A = libft/libft.a

GET_SRCS = $(shell find $(DIR_SRCS))

FILTER_SRCS = $(filter %.c, $(GET_SRCS))

OBJS = $(FILTER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(COMPILER) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	cd libft && make && cd ..

.c.o:
	$(COMPILER) -c $< -o $@ -I $(DIR_INCLUDES)

clean:
	$(RM) $(OBJS)
	cd libft && make clean && cd ..

fclean: clean
	$(RM) $(NAME) $(LIBFT_A)

re: fclean all
