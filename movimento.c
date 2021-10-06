#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

//Estrutura de imagens

typedef struct	s_img
{
	void	*ptr;
	int		x;
	int		y;
}				t_img;

//Estrutura geral

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;
	t_img	c; // personagem
	t_img	f; // chão
}		t_ptr;

//Função para agir a cada tecla apertada

int	key_input(int key, t_ptr *ptr)
{
	int x;

	x = 0;
	if (key == 'a')
		ptr->c.x -= 20;
	else if (key == 'd')
		ptr->c.x += 20;
	else if (key == 'p')
		exit(1);

	//Destroy imagem atual
	mlx_clear_window(ptr->mlx, ptr->win);

	//Renderiza mapa novamente
	while (x < 10)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->f.ptr, (50 * x), 0);
		x++;
	}
	//Printa player na nova posição
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->c.ptr, ptr->c.x, 0);
}

int	main(void)
{
	t_ptr	ptr;
	int	x;
	int	y;

	//Posição inicial do player
	ptr.c.x = 0;
	ptr.c.y = 0;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 500, 50, "test");
	ptr.c.ptr=mlx_xpm_file_to_image(ptr.mlx, "img/img.xpm", &x, &y);
	ptr.f.ptr=mlx_xpm_file_to_image(ptr.mlx, "img/floor.xpm", &x, &y);
	mlx_key_hook(ptr.win, key_input, &ptr);
	mlx_loop(ptr.mlx);
}