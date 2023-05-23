TARGET 			= fractol
OBJDIR 			= objs
SRCDIR 			= srcs
INCLUDE_DIR 	= includes
CC 				= gcc

SRC 			= main.c mandelbrot.c utils.c

INC 			:= -I $(INCLUDE_DIR)

OBJ 			= $(addprefix objs/, $(SRC:.c=.o))

MLX 			= ./MLX42/
MLX_LIB 		= $(addprefix $(MLX), libmlx42.a)
MLX_INC			= -I ./MLX42/include
CFLAGS 			= -Wall -Wextra -pthread -Ofast $(INC)

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS FRACTOL$(RESET)]
_INFO		=	[$(YELLOW)INFO FRACTOL$(RESET)]

all: $(TARGET)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS = -ldl -lglfw
	CFLAGS += -Wunused-result
else ifeq ($(UNAME_S), Darwin)
	MLXFLAGS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/
endif

$(TARGET): $(OBJ)
	@make -C MLX42
	@printf "$(_INFO)Compiling main executable...\n"
	@$(CC) $(OBJ) $(CFLAGS) $(INC) $(MLX_INC) $(MLX_LIB) $(MLXFLAGS) -lm -o $(TARGET)
	@printf "$(_SUCCESS) $(GREEN)$(TARGET) compiled.$(RESET)\n";

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDE_DIR)/* Makefile
	@mkdir -p $(dir $@)
	@printf "$(_INFO) Compiling: $<\n"
	@$(CC) $(CFLAGS) $(INC) $(MLX_INC) -c -o $@ $<

clean:
	@printf "$(_INFO) Cleaning Object Files\n"
	@make -C MLX42 clean
	@make -C libft clean
	@rm -f $(OBJ)
	@printf "$(_INFO)$(YELLOW) OBJS deleted.$(RESET)\n"

fclean: clean
	@printf "$(_INFO) cleaning remaining files.\n"
	@make -C MLX42 clean
	@make -C libft fclean
	@rm -rf $(TARGET)
	@rm -rf $(OBJDIR)
	@printf "$(_INFO)$(GREEN) project folder cleaned.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus