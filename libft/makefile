NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

INCLUDE_DIR = ./includes/

SRCS_DIR = ./srcs/
SRCS = get_next_line.c get_next_line_utils.c ft_atod.c ft_strfind.c ft_strcat.c \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c \
	ft_strstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c
SRCS_NAME = $(addprefix $(SRCS_DIR), $(SRCS))

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.o)))

vpath %.c $(SRCS_DIR)


all : $(NAME)

$(NAME): $(OBJS)
	ar rcsu $(NAME) $(OBJS)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re