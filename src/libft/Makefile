NAME = libft.a 

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

RM = rm -f

SRC = ft_strdup.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_split.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_itoa.c ft_strjoin.c \
	ft_strmapi.c ft_substr.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c ft_strtrim.c ft_printf.c ft_conversions.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c

OBJ = ${SRC:.c=.o}

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
WHITE=\033[1;37m

.c.o:
	@printf "\r🟡 ${MAGENTA}[COMPILING📦] $<${WHITE}"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@printf "\r\033[K🟡 ${YELLOW}[LIBFT] Compiling libft...${WHITE}\n"
	@$(AR) rcs ${NAME} ${OBJ} >/dev/null 2>&1
	@printf "\r\033[K✅ ${GREEN}[LIBFT] Compiled !${WHITE}\n"

all: $(NAME)

clean:
	@printf "🟡 ${MAGENTA}[CLEANING🧹] libft .o files...${WHITE}\n"
	@$(RM) $(OBJ)
	@printf "✅ ${GREEN}[CLEANED🧹]${WHITE}\n"

fclean: clean
	@printf "🟡 ${MAGENTA}[CLEANING🧹] libft archive...${WHITE}\n"
	@$(RM) $(NAME)
	@printf "✅ ${GREEN}[CLEANED🧹]${WHITE}\n"

re: fclean all
