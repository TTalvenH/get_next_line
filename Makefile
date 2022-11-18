NAME = get_next_line
CFLAGS = -Wall -Werror -Wextra -g 
CC = cc
SRC = get_next_line.c get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRC)

clean:

fclean: clean
	rm -f $(NAME)
	
re: fclean all