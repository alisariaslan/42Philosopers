NAME	= philosophers
FLAGS	= -Wall -Wextra -Werror

$(NAME): all

all: *.c *.h
	gcc *.c -o $(NAME)

test: all
	./$(NAME) 100 300 200 100

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re