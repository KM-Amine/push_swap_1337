NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I . 
RM = rm -rf

LFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a 
LSRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_printf.c \
	ft_printf_utils.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c 
LOBJ = $(LSRC:%.c=libft/%.o)

SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=objs/%.o)

OBJDIR = objs

#---->deleet this shit
fgit:
	./git.sh
#---->deleet this shit

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "\033[1;32m ----Mandatory created----- \033[0m"

objs/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(LIBFT) : $(LOBJ)
	@$(MAKE) -C libft
libft/%.o: libft/%.c
	@$(CC) $(LFLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJDIR)
	@$(MAKE) fclean -C libft
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m ----Project cleaned----- \033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
