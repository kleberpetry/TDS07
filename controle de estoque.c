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
int sequencia=0;

cadastrarProduto(){
	system("cls");
	produtos[sequencia].codigo=sequencia+1;
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	printf("\nDigite o valor unitário: ");
	scanf("%lf",&produtos[sequencia].valorUnitario);
	fflush(stdin);
	printf("\nDigite a quantidade do estoque inicial: ");
	scanf("%d",&produtos[sequencia].estoque);
	system("cls");
	printf("\nConfira o cadastro");
	printf("\nCódigo: %d",produtos[sequencia].codigo);
	printf("\nNome: %s",produtos[sequencia].nome);
	printf("\nValor unitário: %0.2lf",produtos[sequencia].valorUnitario);
	printf("\nEstoque: %d\n",produtos[sequencia].estoque);
	
	sequencia++;
	system("pause");
}

/*	int codigo;
	char nome[50];
	double valorUnitario;
	int estoque;*/







main(){
	setlocale(LC_ALL, "Portuguese");
	int x;
	system("cls");
	printf("\nDigite 1 para cadastrar um produto\nDigite 2 para dar entrada em estoque\nDigite 3 para ajustar um estoque\nDigite 4 para listar todos os produtos\nDigite 5 para buscar um produto por codigo\nDigite sua opção: ");
	scanf("%d",&x);
	switch(x){
		case 1:
			cadastrarProduto();
		break;
		case 2:
			//entradaEstoque();
		break;
		case 3:
			//ajusteEstoque();
		break;
		case 4:
			//listarProdutos();
		break;
		case 5:
			//buscarProduto();
		break;
		default:
			printf("\nOpção inválida\n");
	}
	return 0;
}
