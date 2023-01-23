NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -I .
RM = rm -rf

BONUS = checker
LIBFT = libft/libft.a 
SRC = $(wildcard srcs/*.c)

OBJ = $(SRC:srcs/%.c=objs/%.o)

BSRC = $(wildcard bonus/*.c)
BOBJ = $(BSRC:bonus/%.c=bobjs/%.o)

OBJDIR = objs
BOBJDIR = bobjs


all: libft-lib $(NAME)

#---->deleet this shit
fgit:
	./git.sh
#---->deleet this shit
#always call libft in all to solve touching libft files

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)  -o $(NAME)
	@echo "\033[1;32m ----Mandatory created----- \033[0m"

objs/%.o: srcs/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

libft-lib :
	@$(MAKE) -C libft 

bonus: libft-lib $(BONUS)

$(BONUS): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT)  -o $(BONUS)
	@echo "\033[1;32m ----bonus created----- \033[0m"

bobjs/%.o: bonus/%.c
	@mkdir -p $(BOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJDIR) $(BOBJDIR)
	@$(MAKE) fclean -C libft
fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "\033[1;32m ----Project cleaned----- \033[0m"

re: fclean all

.PHONY: all clean fclean re bonus libft-lib
