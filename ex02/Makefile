NAME = ./ex02
CPP = /bin/c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp Bureaucrat.cpp Form.cpp
OBJ_DIR = ./obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CPP) -c $< -o $@ $(CPPFLAGS)
	
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
