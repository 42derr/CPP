CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

NAME = phoneBook
SRCS = src/contact.cpp src/phoneBook.cpp src/phoneBookUtils.cpp src/main.cpp
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