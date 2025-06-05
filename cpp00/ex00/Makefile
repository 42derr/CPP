CXX = c++

INCLUDES= .

SRCS = megaphone.cpp

CXXFLAGS = -Wall -Wextra -Werror -MMD
CXXFLAGS += -std=c++98 -I$(INCLUDES)

NAME = megaphone
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
