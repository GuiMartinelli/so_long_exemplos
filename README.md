# so_long_exemplos

Breve resumo do bate-papo do dia 05/10 em exemplos comentados

# Como usar

Rode `make` + `nome do teste`, um executável **so_long** será criado, e é só executar com `./so_long`

# Testes

**print_imagem**: Como carregar uma imagem em um ponteiro, e printar em uma janela

**mapa**: Introdução de como podemos transformar uma string em um mapa

**key_hook**: Introdução à função `mlx_key_hook`

**movimento**: Princípios de movimentação de imagem, usando a função `mlx_key_hook`

**path**: Exemplo de como definimos os paths em nossos arquivos

# Corrigindo Seg Faults

É comum encontrar vários erros durante o desenvolvimento do projeto, ao encontrar um Seg Fault, duas dicas para procurar primeiro são:

-Ponteiros `mlx` ou `win` mal ultilizados
	Caso coloque-os no lugar errado em alguma função, isso quebrará seu programa
	Exemplo : `	win = mlx_new_window(WIN, 100, 100, "teste");`

-Path errado ao carregar imagens ou o mapa
	Se o path estiver errado, seu ponteiro de imagem ou sua matriz de mapa serão NULL, e quebrará seu programa ao tentar coloca-los na janela
