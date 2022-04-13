#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct produto{
	int codigo;
	char nome[50];
	double valorUnitario;
	int estoque;
};
struct produto produtos[200];

cadastrarProduto(){
	
}


main(){
	setlocale(LC_ALL, "Portuguese");
	int x;
	system("cls");
	printf("\nDigite 1 para cadastrar um produto\nDigite 2 para dar entrada em estoque\nDigite 3 para ajustar um estoque\nDigite 4 para listar todos os produtos\nDigite 5 para buscar um produto por codigo\nDigite sua opção: ");
	
	//cadastro produto
	//entrada de estoque
	//ajuste de estoque
	//listar todos produtos
	//busca produto
	//venda
	
	
	
	return 0;
}
