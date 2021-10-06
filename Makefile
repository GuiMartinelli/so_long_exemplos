NAME = so_long

FLAGS = -Wall -Wextra -Werror -fsanitize=address

MINILIBX = -Imlx -lX11 -lXext

LIBS = mlx/libmlx_Linux.a

movimento:
	gcc movimento.c $(LIBS) $(MINILIBX) -o $(NAME)

print_imagem:
	gcc print_imagem.c $(LIBS) $(MINILIBX) -o $(NAME)

mapa:
	gcc mapa.c $(LIBS) $(MINILIBX) -o $(NAME)

key_hook:
	gcc key_hook.c $(LIBS) $(MINILIBX) -o $(NAME)

path:
	gcc dir/path.c $(LIBS) $(MINILIBX) -o $(NAME)

run: all
	./so_long