NAME = pipex
CFLAGS = -I $(INCLUDES) -Wall -Wextra -Werror

SRCS = pipex.c
SRCS_B = pipex_bonus.c heredoc_bonus.c

TO_COMPILE = $(if $(filter bonus, $(MAKECMDGOALS)), $(addprefix bonus/, $(SRCS_B)), $(addprefix mandatory/, $(SRCS)))
INCLUDES = ./includes/
SHELL = bash

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(TO_COMPILE) $(INCLUDES)
	@echo -n "Creating a program : "
	@make all -s -C libft
	@cc $(CFLAGS) $(TO_COMPILE) ./libft/libft.a -o $@ 
	@echo -e "\033[32;1m"complete"\033[0m"
	@sleep 0.2

clean :
	@echo -n "Deleting object files : "
	@make clean -s -C libft
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

fclean :
	@echo -n "Deleting all files : "
	@make fclean -s -C libft
	@rm -f pipex
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

re : 
	@make fclean
	@make all

rebonus : 
	@make fclean
	@make bonus

.PHONY : all clean fclean re bonus