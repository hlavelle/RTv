NAME	= RTv1

SRC		= src/rtv.c src/exit.c src/parcer.c src/checks.c src/events.c \
src/init.c src/utils.c src/ray.c src/vectors.c src/vectors_rotate.c src/structs_utils.c \
src/vectors_2.c src/parcer_shapes.c src/intersection_shapes.c src/vectors_3.c

OBJ		= $(patsubst sources/%.c,objects/%.o,$(SRC))

SDL_INCLUDES	= -I ~/include
SDL		= ~/lib/libSDL2.a
SDL_LINK	= -L ~/lib -lSDL2

LIBFT_DIRECTORY 	= ./lib/libft 
LIBFT		= ./lib/libft/libft.a
LIBFT_INCLUDES	= -I ./lib/libft/include
LIBFT_LINK	= -L ./lib/libft -lft

LINKS	+=	$(LIBFT_LINK)
LINKS	+=	$(SDL_LINK)
LINKS	+=	-lm

INCLUDES =	-I ./include
INCLUDES	+=	$(LIBFT_INCLUDES)
INCLUDES	+=	$(SDL_INCLUDES)

CC_WITH_FLAGS = clang -Wall -Wextra -Werror -O1

.SILENT:

all: $(LIBFT) $(SDL) $(NAME)

$(SDL):
	./build_sdl.sh

$(LIBFT):
	make -C $(LIBFT_DIRECTORY)

$(NAME): $(OBJ) $(LIBFT) $(SDL)
	$(CC_WITH_FLAGS) $(SRC) $(LINKS) $(INCLUDES) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create RTv1"

objects/%.o: sources/%.c
	mkdir -p objects
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf objects/
	make -C $(LIBFT_DIRECTORY) clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean RTv1"

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT_DIRECTORY) fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean RTv1"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
