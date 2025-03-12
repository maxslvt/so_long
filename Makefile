CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

NAME = so_long

SRC = src/main.c src/ft_texture.c src/ft_map.c src/ft_hook.c src/ft_hook_utils.c src/ft_utils.c src/ft_check.c src/ft_check_utils.c src/ft_map_utils.c src/ft_printables.c

LIBFT_DIR = ./src/libft/

LIBFT = libft.a

MLX = mlx/libmlx.a

OBJETS = $(SRC:.c=.o)

RED=\033[0;31m

GREEN=\033[0;32m

YELLOW=\033[0;33m

WHITE=\033[0m

BLUE = \033[0;36m

$(NAME) : $(MLX) $(OBJETS)
	@printf "$(YELLOW)TRYING TO COMPILE SO_LONG...$(WHITE)\n"
	@printf "$(YELLOW)COMPILING LIBFT...$(WHITE)\n"
	@make libft
	@printf "$(GREEN)LIBFT COMPILED !$(WHITE)\n"
	@cc $(CFLAGS) -o $(NAME) $(OBJETS) $(MLXFLAGS) -g $(LIBFT_DIR)$(LIBFT)
	@printf "\r$(GREEN)SO_LONG COMPILED !$(WHITE)"

all : $(NAME)

$(MLX):
	@printf "$(YELLOW)TRYING TO DOWNLOAD MINILIBX...$(WHITE)\n"
	@git clone https://github.com/42Paris/minilibx-linux mlx
	@printf "$(GREEN)MINILIBX DOWNLOADED !$(WHITE)\n"
	@printf "$(YELLOW)TRYING TO COMPILE MINILIBX...$(WHITE)\n"
	@make -s minilibx
	@printf "$(GREEN)MINILIBX COMPILED !$(WHITE)\n"

minilibx:
	@make -C mlx >/dev/null 2>&1

libft:
	@make -C $(LIBFT_DIR)
	
.c.o:

clean :
	@printf "$(YELLOW)CLEANING ".o" FILES...$(WHITE)\n"
	@rm -f $(OBJETS)
	@if [ -d mlx ]; then \
	make -C mlx clean >/dev/null;\
	fi
	@make -C $(LIBFT_DIR) clean >/dev/null
	@printf "\r$(GREEN)".o" FILES ARE CLEANED !$(WHITE)\n"

fclean : clean
	@printf "\r$(YELLOW)CLEANING MLX AND LIBFT...$(WHITE)\n"
	@make -C $(LIBFT_DIR) fclean >/dev/null
	@if [ -d mlx ]; then \
	rm -rf mlx;\
	fi
	@rm -f ${NAME}
	@printf "\r$(GREEN)FCLEANED WITH SUCCESS !$(WHITE)\n"

re : fclean all

.PHONY : all clean fclean re