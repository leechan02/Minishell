NAME = minishell
CFLAGS = -I $(INCLUDES) -MMD
RFLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib -I${HOME}/.brew/opt/readline/include

SRCS_PARSE := $(addprefix parse/, parse_env.c parse_quote.c parse_redir.c parse_split.c parse.c)

SRCS_DIR = ./srcs/
SRCS = main.c $(SRCS_PARSE)
SRCS_NAME = $(addprefix $(SRCS_DIR), $(SRCS))

INCLUDES = ./includes/
SHELL = bash

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.d)))

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@echo -n "Making minishell... "
	@make all -s -C libft
	@cc -g -Wall -Wextra -Werror $(OBJS) $(RFLAGS) ./libft/libft.a -o $@ 
	@echo -e "\033[32;1m"complete"\033[0m"
	@sleep 0.2

$(OBJ_DIR) :
	@mkdir $@

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	@cc -g $(CFLAGS) -c $< -o $@

clean :
	@echo -n "Deleting object files : "
	@make clean -s -C libft
	@rm -rf $(OBJ_DIR)
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

fclean : clean
	@echo -n "Deleting minishell : "
	@make fclean -s -C libft
	@rm -f minishell
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re

-include $(DEPS)