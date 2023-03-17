NAME		= RPN
SRCSDIR		= .
OBJSDIR		= objs
INCLUDES	= .
SRCS		= srcs/main.cpp \
				srcs/RPN.cpp
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)
$(NAME): $(SRCSDIR)/$(SRCS)
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $^
clean:
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re test