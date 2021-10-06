#include "mlx/mlx.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	char	mapa[10] = {"100011001"}; //Exemplo de mapa de uma linha só
	int	y;
	int	x;
	int	index;

	index = 0;
	mlx = mlx_init();

	//A janela tem 500x50 porque, cada sprite do mapa tem 50x50, e serão 10 sprites na linha, faça sua janela se adaptar ao tamanho do mapa,
	//ao ler o mapa você sabera quantas linhas tem e qual o tamanho delas, multiplique pelo tamanho de seus sprites(faça-os de tamanhos iguais)
	win = mlx_new_window(mlx, 500, 50, "teste");

	//Armazenando o chão e paredes nos ponteiros, dimensões ficam guardadas em x e y porque não vamos usar agora, mas armazene bem esses dados
	floor = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &x, &y);
	wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &x, &y);

	//Loop para printar a textura, vai ler o mapa e se o caractere for 1, printa parede, se não, printa chão
	while (index < 10)
	{
		if (mapa[index] == '1')
			mlx_put_image_to_window(mlx, win, wall, (50 * index), 0);
		else
			mlx_put_image_to_window(mlx, win, floor, (50 * index), 0);
		index++;
	}
	mlx_loop(mlx);
}