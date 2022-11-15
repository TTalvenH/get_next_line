NAME = get_next_line
CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
SRC = get_next_line.c

all: $(NAME)

$(NAME): $(SRC)

clean:

fclean: clean
	rm -f $(NAME)
	
re: fclean all