NAME = push_swap

NAME2 = checker

SRCS = push_swap.c verif.c rotate.c push_and_swap.c check.c init_size_count.c \
print_list.c ft_lstaddint.c main.c regroup_stack.c push_swap2.c \
ft_few_command.c merge_sort.c

OBJECT = $(SRCS:.c=.o)

$(NAME): 
		make -C libft/
		gcc -Wall -Werror -Wextra -o $(NAME) $(SRCS) libft/libft.a
		cp $(NAME) $(NAME2)

all: $(NAME)

clean:
	rm -f $(OBJECT)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME) $(NAME2)
	make -C libft/ fclean

re: fclean all
	make -C libft/ re

.PHONY: all clean fclean re
