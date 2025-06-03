NAME = converter

CC = c++

CXXFLAGS = -Werror -Wall -Wextra -std=c++98

SRCS = converter.cpp main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all

