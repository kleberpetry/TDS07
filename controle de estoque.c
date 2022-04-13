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
listarProdutos(){
	system("cls");
	int x;
	if(produtos[0].codigo>0){
		for(x=0;x<sequencia;x++){
			printf("\n______________________________\n");
			printf("\nCódigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nValor unitário: %0.2lf",produtos[x].valorUnitario);
			printf("\nEstoque: %d\n",produtos[x].estoque);
		}
	}else{
		printf("\nNenhum projeto cadastrado\n");
	}
	
	system("pause");
}








main(){
	setlocale(LC_ALL, "Portuguese");
	int x;
	do{
		system("cls");
		printf("\nDigite 1 para cadastrar um produto\nDigite 2 para dar entrada em estoque\nDigite 3 para ajustar um estoque\nDigite 4 para ajustar o valor\nDigite 5 para listar todos os produtos\nDigite 6 para buscar um produto por codigo\nDigite sua opção: ");
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
				//ajusteValor();
			break;
			case 5:
				listarProdutos();
			break;
			case 6:
				//buscarProduto();
			break;
			default:
				printf("\nOpção inválida\n");
		}
	}while(x!=0);
	return 0;
}
