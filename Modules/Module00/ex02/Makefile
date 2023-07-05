NAME = converter
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
LDFLAGS =
SRCS = main.cpp \
	Converter.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%o: %cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re