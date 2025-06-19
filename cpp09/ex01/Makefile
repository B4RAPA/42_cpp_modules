NAME = RPN

CC = c++

CFLAGS = -Werror -g -Wall -Wextra -std=c++98

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all
