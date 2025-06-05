CXX = c++
INCLUDES = .
CXXFLAGS = -Wall -Wextra -Werror -MMD
CXXFLAGS += -std=c++98 -I$(INCLUDES)

NAME = human
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(DEPS)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
