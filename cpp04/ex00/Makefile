CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

NAME = animal
SRCS = src/main.cpp src/Animal.cpp src/Dog.cpp src/Cat.cpp src/WrongAnimal.cpp src/WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -Iincludes $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) -Iincludes $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re