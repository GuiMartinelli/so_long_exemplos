#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "teste");

	//Armazena imagem do path "img/img.xpm" no ponteiro img, dimensões ficam guardadas em x e y
	img = mlx_xpm_file_to_image(mlx, "img/img.xpm", &x, &y);

	//Printa a imagem do ponteiro no pixel 0x0 da janela >>Se o path estiver errado na função acima, o ponteiro sera NULL e quebrará o programa<<
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}