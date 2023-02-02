NAME = minishell
CFLAGS = -I $(INCLUDES) -g #-Wall -Wextra -Werror
RFLAGS = -lreadline -L/Users/euiclee/.brew/opt/readline/lib -I/Users/euiclee/.brew/opt/readline/include

SRCS_DIR = ./srcs/
SRCS = main.c
SRCS_NAME = $(addprefix $(SRCS_DIR), $(SRCS))

INCLUDES = ./includes/
SHELL = bash

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.o)))

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS) $(INCLUDES)
	@echo -n "Making minishell... "
	@make all -s -C libft
	@cc $(OBJS) $(RFLAGS) ./libft/libft.a -o $@ 
	@echo -e "\033[32;1m"complete"\033[0m"
	@sleep 0.2

$(OBJ_DIR) :
	@mkdir $@

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	@cc $(CFLAGS) $(RFLAGS) -c $< -o $@

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