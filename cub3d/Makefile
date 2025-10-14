# ───────── Project ─────────
NAME        := cub3D
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -g -gdwarf-4 -MMD -MP
INCLUDES    := -I include -I libft -I mlx

# ───────── Sources / Objects ─────────
SRC_DIRS    := src src/engine src/init_check src/parsing src/utils
SRCS        := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.c))
OBJS        := $(SRCS:.c=.o)
DEPS        := $(OBJS:.o=.d)

# ───────── libft ─────────
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

# ───────── MiniLibX ─────────
# BACKEND può essere: ogl (OpenGL, default) oppure metal
BACKEND     ?= ogl
MLX_DIR     := mlx
MLX_A       := $(MLX_DIR)/libmlx.a

ifeq ($(BACKEND),metal)
  # macOS + Metal (Apple Silicon o Intel recente)
  MLX_LDFLAGS := -L $(MLX_DIR) -lmlx -framework Cocoa -framework Metal -framework QuartzCore
else
  # macOS + OpenGL (Mac non-Metal / legacy)
  MLX_LDFLAGS := -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# ───────── Rules ─────────
.PHONY: all dev clean fclean re mlx libft

all: $(NAME)

dev: CFLAGS += -DDEV_STUB
dev: $(NAME)

$(NAME): libft mlx $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) $(MLX_LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft: $(LIBFT_A)
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

mlx: $(MLX_A)
$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(DEPS)
	-$(MAKE) -C $(LIBFT_DIR) clean
	-$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)
