FT_CONTAINERS_DIR = ft_containers

FT_CONTAINERS_INCLUDES = $(FT_CONTAINERS_DIR)/includes

NAME = tester

CC = clang++

SAN_FLAGS = -Werror -Wextra -Wall -Wconversion -std=c++98 -g3 -fsanitize=address

FLAGS = -Werror -Wextra -Wall -Wconversion -std=c++98 -g3

CCF = $(CC) $(FLAGS)

CCFF = $(CC) $(SAN_FLAGS)

TEST = srcs/List_Tests.hpp

RM = rm -f

RMF = rm -rf

all: $(NAME)
	@./$(NAME)
	@$(RMF) $(NAME).dSYM

$(NAME): $(TEST) srcs/main.cpp
	@$(CCF) srcs/main.cpp -o $@ -I$(FT_CONTAINERS_INCLUDES)

fsan: $(TEST) srcs/main.cpp
	@$(CCFF) srcs/main.cpp -o $(NAME) -I$(FT_CONTAINERS_INCLUDES)
	@./$(NAME)
	@$(RMF) $(NAME).dSYM

clean:
	@$(RM) $(LIST_OBJS) $(NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
	@./$(NAME)
ref: fclean fsan
	@printf "\e[93mFSANITIZE ACTIVATED !\n\e[0m"
	@./$(NAME)

rel: fclean all
	@printf "\e[92mLEAKS CHECK !\n\e[0m"
	@leaks -atExit -- ./$(NAME)