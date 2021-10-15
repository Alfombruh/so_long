.DEFAULT_GOAL := all
NAME = so_long
CC = clang
#CSANITIZE = -fsanitize=address -g3
CFLAGS = -Werror -Wextra -Wall -g
MLXFLAGS = -lmlx -framework OPENGL -framework Appkit
RM = rm -f

FILES = ft_errors	\
		ft_map		\
		ft_getdata	\
		map_check	\
		so_long		\
		libft/ft_itoa \
		movement/ft_movefoward \
		movement/ft_movedown   \
		movement/ft_moveleft   \
		movement/ft_moveright

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all : $(NAME)

.c.o: $(FILES) $(NAME)
	@$(CC) $(CSANITIZE) $(CFLAGS) -Imlx -c -o $@ $^

$(NAME) : $(OBJS) 
	@printf "\e[32mHowdy Partner! The code is compiling 🤠\e[0m\n"
	@$(MAKE) -s -C libft 
	@$(MAKE) -s -C mlx 
	@mv mlx/libmlx.a .
	@$(CC) $(CSANITIZE) $(CFLAGS) $(OBJS) -L . $(MLXFLAGS) -o $(NAME) 
	@printf "\e[32m😎👌\ncompilado master\e[0m\n"

clean :
	@$(RM) $(OBJS) libft/*.o mlx/*.o movement/*.o 
	@printf "\e[31m.o files deleted🗑️\e[0m\n"

fclean : clean
	@$(RM) $(NAME) libft/libft.a libmlx.a 
	@printf "\e[31mso_long, libmlx.a and libft.a deleted🗑️\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
