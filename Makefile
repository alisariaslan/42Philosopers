NAME	= philosophers
FLAGS	= -Wall -Wextra -Werror

OBJ_DIR = obj

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c src/*.h | $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

test: all
	./$(NAME) 100 300 200 100

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf src/$(NAME)

re:	fclean all

.PHONY:	all clean fclean re