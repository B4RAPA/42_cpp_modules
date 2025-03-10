NAME = accounts

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE = Account.hpp

SRCS = Account.cpp\
		tests.cpp

OBJS = Account.o\
		tests.o
	
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re