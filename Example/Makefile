NAME	= philo
FLAGS	= -Wall -Wextra -Werror

all: *.c *.h
	gcc *.c -o $(NAME)

$(NAME): all

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re