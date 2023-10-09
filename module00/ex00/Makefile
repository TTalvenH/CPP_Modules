# Program name
NAME = megaphone

# compiler
CC = c++

# compiler flags
CFLAGS = -std=c++98 -Wall -Werror -Wextra -MMD
DEBUG_FLAGS = -g -fsanitize=address

# src files and path for them
VPATH = ./
SRC = megaphone.cpp

# obj files and path for them
OBJ_DIR = ./obj
OBJ =$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

#dependencies
DEP =$(OBJ:%.o=%.d)

# rules
all: $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	
-include $(DEP)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all debug clean fclean re