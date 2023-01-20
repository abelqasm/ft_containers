SRCS = test.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -fsanitize=address -g3
NAME = ./test

all:
	$(CC) -g $(CPPFLAGS) $(LDFLAGS) $(SRCS) -o $(NAME)

run:
	$(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all