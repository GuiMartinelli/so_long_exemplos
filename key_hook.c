#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>


// Função simples que printa a tecla apertada no terminal, e fecha o programa ao apertar P
//>>Atenção ao protótipo da função, int	func(int), onde o primeiro argumento é a tecla pressionada, e o segundo é o que você definiu na mlx_key_hook(linha 28),
//caso tenha definido, se não definir nenhum, ela recebe apenas o primeiro argumento (print_key(int key))<<<
int	print_key(int key, char *str)
{
	//Printa o argumento passado na mlx_key_hook
	printf("%s\n", str);
	printf("%c\n", key);
	if (key == 'p')
		exit(1);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "teste");

	//Função da lib para reagir à inputs do teclado, mlx_hook também tem várias opções uteis, mas é mais complexa
	//O terceiro argumento é opcional, caso não acrescente nenhum, defina como (void *)0
	mlx_key_hook(win, print_key, "Oi");
	mlx_loop(mlx);
}