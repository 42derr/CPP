CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
#CXXFLAGS += -std=c++98  # Uncomment if using C++98 standard

NAME = my_program  # Set your executable name here
SRCS = main.cpp utils.cpp  # List your source files here
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
