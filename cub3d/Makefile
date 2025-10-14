# ───────── Project ─────────
NAME        := cub3D
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -g -gdwarf-4 -MMD -MP
INCLUDES    := -I include -I libft -I mlx

# Dove mettere artefatti
BUILD_DIR   := build
BIN_DIR     := bin

# ───────── Sources / Objects ─────────
SRC_DIRS    := src src/engine src/init_check src/parsing src/utils
SRCS        := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.c))
OBJS        := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS        := $(OBJS:.o=.d)
TOTAL       := $(words $(OBJS))
BAR_WIDTH   ?= 30

# ───────── libft ─────────
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

# ───────── MiniLibX ─────────
# BACKEND può essere: ogl (OpenGL, default) oppure metal
BACKEND     ?= ogl
MLX_DIR     := mlx
MLX_A       := $(MLX_DIR)/libmlx.a

ifeq ($(BACKEND),metal)
  MLX_LDFLAGS := -L $(MLX_DIR) -lmlx -framework Cocoa -framework Metal -framework QuartzCore
else
  MLX_LDFLAGS := -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Evita build parallela: la barra richiede ordine
.NOTPARALLEL:

# ───────── Rules ─────────
.PHONY: all dev clean fclean re mlx libft run prep

all: $(BIN_DIR)/$(NAME)

dev: CFLAGS += -DDEV_STUB
dev: $(BIN_DIR)/$(NAME)

# Inizializza contatori barra
prep:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)
	@echo $(TOTAL) > $(BUILD_DIR)/.total
	@echo 0 > $(BUILD_DIR)/.count
	@printf "Compiling %d files...\n" $(TOTAL)

# Link finale nel bin/ + newline per chiudere la barra
$(BIN_DIR)/$(NAME): prep libft mlx $(OBJS)
	@mkdir -p $(dir $@)
	@printf "\nLinking %s...\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) $(MLX_LDFLAGS) -o $@
	@printf "✔ Build done: %s\n" $@

# Compilazione: .c -> build/.../.o (+ .d)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@{ \
	 cnt=$$(( $$(cat $(BUILD_DIR)/.count 2>/dev/null || echo 0) + 1 )); \
	 echo $$cnt > $(BUILD_DIR)/.count; \
	 total=$$(cat $(BUILD_DIR)/.total 2>/dev/null || echo $(TOTAL)); \
	 width=$(BAR_WIDTH); \
	 pct=$$(( 100 * $$cnt / $$total )); \
	 done=$$(( $$cnt * $$width / $$total )); \
	 remain=$$(( $$width - $$done )); \
	 printf "\r["; \
	 printf "%0.s#" $$(seq 1 $$done); \
	 printf "%0.s " $$(seq 1 $$remain); \
	 printf "] %3d%% (%d/%d) %-40s" $$pct $$cnt $$total "$<"; \
	}

libft: $(LIBFT_A)
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

mlx: $(MLX_A)
$(MLX_A):
	@$(MAKE) -C $(MLX_DIR) BACKEND=$(BACKEND)

clean:
	@$(RM) -r $(BUILD_DIR)
	-@$(MAKE) -C $(LIBFT_DIR) clean
	-@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@$(RM) -r $(BIN_DIR)
	-@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)

run: $(BIN_DIR)/$(NAME)
	@./$(BIN_DIR)/$(NAME)
