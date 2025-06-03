NAME = Bureaucrate

CC = c++

CFLAGS = -Werror -Wall -Wextra -std=c++98

SRCS = src/Bureaucrat.cpp src/main.cpp src/AForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/ShrubberyCreationForm.cpp

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