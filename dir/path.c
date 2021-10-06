#include "../mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "teste");

	//PATH ERRADO, o Path deve ser relativo ao >>executável so_long<<, que está na pasta raiz, e não relativo ao arquivo .c
	//img = mlx_xpm_file_to_image(mlx, "../img/img.xpm", &x, &y);

	//Path certo!!!
	img = mlx_xpm_file_to_image(mlx, "img/img.xpm", &x, &y);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}