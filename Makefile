############################################################################################################
# Variables

NAME		=	so_long

LIBFT_PATH = ./libft/libft.a

INC_DIR		=	./includes/
SL_HEADER_FILE = $(INC_DIR)/so_long.h

SRC_DIR		=	./sources
SRCS		=	$(addprefix $(SRC_DIR)/, \
				core/main.c core/map.c core/event.c core/move.c \
				core/logic.c core/monster_logic.c \
				utils/init.c utils/mem.c utils/open_ber.c utils/img_path_check.c\
				utils/prints_n_exits.c utils/validate_path.c utils/render.c \
				)

# Objects			
OBJ_DIR		=		./obj
OBJ			=		$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
GFLAGS = -lXext -lX11 -lm -lbsd
GPATH = ./mlx/
MLX_PATH = $(GPATH)/libmlx_Linux.a

RM = rm -f

# Colors
GREEN		=		\033[0;32m
UGREEN		=		\033[4;32m
RED			=		\033[0;31m
YELLOW		=		\033[0;33m
LILA		=		\033[0;35m
NC			=		\033[0m # No color


############################################################################################################
# Rules

all: ascii_art

ascii_art:
	@if ! $(MAKE) -q $(NAME); then \
		printf "$(LILA)\n"; \
		printf "███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ \n"; \
		printf "██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ \n"; \
		printf "███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗\n"; \
		printf "╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║\n"; \
		printf "███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝\n"; \
		printf "╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n"; \
		printf "		     				    MRUBAL-C\033[0m\n"; \
		echo "$(YELLOW)\nCreating program...$(GREEN)"; \
		$(MAKE) -s $(NAME); \
	else \
		echo "$(GREEN)[$(NAME)] is already up to date.$(NC)"; \
	fi

$(NAME): $(LIBFT_PATH) $(MLX_PATH) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH) $(MLX_PATH) $(GFLAGS) -o $(NAME)
	@echo  "█"
	@printf "$(UGREEN)%s$(NC)" "[so_long]"
	@printf "$(GREEN)%s$(NC)\n" " Compiled successfully."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -n "██"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT_PATH):
	@echo -n "██"
	@[ -f $(LIBFT_PATH) ] || make -s -C ./libft

$(MLX_PATH):
	@echo -n "██"
	make -s -C $(GPATH) >/dev/null 2>&1

clean:
	@make -s clean -C ./libft
	@make -s clean -C $(GPATH)
	@$(RM) -rf $(OBJ_DIR)

fclean:
	@make -s fclean -C ./libft
	@make -s clean -C $(GPATH)
	@echo "$(RED)Removing program... 🧹$(NC)"
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(GREEN)Full clean complete 🗑️$(NC)"

a: all bonus

re: fclean all

rebonus: fclean bonus

ra: fclean a

.PHONY: all bonus clean fclean a re rebonus ra
############################################################################################################
