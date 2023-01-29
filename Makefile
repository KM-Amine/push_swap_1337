NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = push_swap.h
LIBFT = libft/libft.a 

OBJ = objs/0-main.o \
	objs/1-args_check.o \
	objs/1-args_utils.o \
	objs/1-errors_handler.o \
	objs/1-number_generator.o \
	objs/1-tab_utils.o \
	objs/2-stack_creation.o \
	objs/2-stack_operations_1.o \
	objs/2-stack_operations_2.o \
	objs/2-stack_operations_3.o \
	objs/3-sorting_system_1.o \
	objs/3-sorting_system_2.o \
	objs/3-sorting_system_3.o \
	objs/ft_atoi_max.o \

BOBJ = bobjs/0-main.o \
	bobjs/1-args_check.o \
	bobjs/1-args_utils.o \
	bobjs/1-errors_handler.o \
	bobjs/1-number_generator.o \
	bobjs/1-tab_utils.o \
	bobjs/2-stack_creation.o \
	bobjs/2-stack_operations_1.o \
	bobjs/2-stack_operations_2.o \
	bobjs/2-stack_operations_3.o \
	bobjs/7-checking_system_1.o \
	bobjs/7-checking_system_2.o \
	bobjs/ft_atoi_max.o \

OBJDIR = objs
BOBJDIR = bobjs

all: libft-lib $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)  -o $(NAME)
	@echo "\033[1;32m ----Mandatory created----- \033[0m"

objs/%.o: srcs/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

libft-lib :
	@$(MAKE) -C libft 

bonus: libft-lib $(BONUS)

$(BONUS): $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT)  -o $(BONUS)
	@echo "\033[1;32m ----bonus created----- \033[0m"

bobjs/%.o: bonus/%.c $(HEADER)
	@mkdir -p $(BOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJDIR) $(BOBJDIR)
	@$(MAKE) fclean -C libft
fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "\033[1;32m ----Project cleaned----- \033[0m"
re: fclean all
bre: fclean bonus

.PHONY: all clean fclean re bonus bre libft-lib

