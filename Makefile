NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRC = src/main.c src/ft_texture.c src/ft_map.c src/ft_hook.c src/ft_hook_utils.c src/ft_utils.c src/ft_check.c src/ft_check_utils.c src/ft_map_utils.c src/ft_printables.c

LIBFT_DIR = ./src/libft/

LIBFT = libft.a

MLX = mlx/libmlx.a

OBJETS = $(SRC:.c=.o)

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
WHITE=\033[1;37m

$(NAME) : $(MLX) $(OBJETS)
	@make libft --no-print-directory
	@printf "\r\033[K🟡 ${YELLOW}[SO_LONG] Compiling so_long...${WHITE}\n"
	@cc $(CFLAGS) -o $(NAME) $(OBJETS) $(MLXFLAGS) -g $(LIBFT_DIR)$(LIBFT)
	@printf "\r\033[K✅ ${GREEN}[SO_LONG] Compiled !${WHITE}\n"

$(MLX):
	@printf "🟦 ${CYAN}[MLX] Downloading minilibx...${BLUE}\n"
	@git clone https://github.com/42Paris/minilibx-linux mlx
	@printf "✅ ${GREEN}[MLX] Downloaded !${WHITE}\n"
	@printf "🟦 ${YELLOW}[MLX] Compiling minilibx...${WHITE}\n"
	@make -s minilibx 
	@printf "✅ ${GREEN}[MLX] Compiled !${WHITE}\n"

minilibx:
	@make -C mlx >/dev/null 2>&1

libft:
	@make -C $(LIBFT_DIR) --no-print-directory

.c.o:
	@printf "\r🟡 [COMPILING📦] $<${WHITE}"
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	@printf "🟡 ${MAGENTA}[CLEANING🧹] .o files...${WHITE}\n"
	@rm -f $(OBJETS)
	@if [ -d mlx ]; then \
		make -C mlx clean >/dev/null;\
	fi
	@make -C $(LIBFT_DIR) clean --no-print-directory >/dev/null
	@printf "✅ ${GREEN}[CLEANED🧹]${WHITE}\n"

fclean : clean
	@printf "🟡 ${MAGENTA}[CLEANING🧹] mlx & libft...${WHITE}\n"
	@make -C $(LIBFT_DIR) fclean --no-print-directory >/dev/null
	@if [ -d mlx ]; then \
		rm -rf mlx;\
	fi
	@rm -f ${NAME}
	@printf "✅ ${GREEN}[CLEANED🧹]${WHITE}\n"

re : fclean all

.PHONY : all clean fclean re
