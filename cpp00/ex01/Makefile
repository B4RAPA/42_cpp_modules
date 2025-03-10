NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE = Contact.hpp PhoneBook.hpp 

SRCS = main.cpp contact.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all flcean clean re
