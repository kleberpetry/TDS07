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
int sequencia=0,nvendas=0;
double vendas[200];

cadastrarProduto(){
	FILE *arquivo;
	system("cls");
	produtos[sequencia].codigo=sequencia+1;
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);// serve exclusivamente para string
	printf("\nDigite o valor unitário: ");
	scanf("%lf",&produtos[sequencia].valorUnitario);
	fflush(stdin);
	printf("\nDigite a quantidade do estoque inicial: ");
	scanf("%d",&produtos[sequencia].estoque);//serve para ambos
	system("cls");
	printf("\nConfira o cadastro");
	printf("\nCódigo: %d",produtos[sequencia].codigo);
	printf("\nNome: %s",produtos[sequencia].nome);
	printf("\nValor unitário: %0.2lf",produtos[sequencia].valorUnitario);
	printf("\nEstoque: %d\n",produtos[sequencia].estoque);
	sequencia++;
	arquivo=fopen("produtos.txt","a");
	fprintf(arquivo,"\nCódigo: %d\nNome: %s\nValor : %0.2lf\nEstoque: %d\n\n"
	,produtos[sequencia].codigo
	,produtos[sequencia].nome
	,produtos[sequencia].valorUnitario
	,produtos[sequencia].estoque);
	fclose(arquivo);
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
listarVendas(){
	system("cls");
	int x;
	if(vendas[0]>0){
		for(x=0;x<nvendas;x++){
			printf("\n______________________________\n");
			printf("\nVenda: %d",x+1);
			printf("\nValor: %0.2lf\n",vendas[x]);
		}
	}else{
		printf("\nNenhuma venda encontrada\n");
	}
	system("pause");
}
entradaEstoque(){
	system("cls");
	int codigo,x,estoque;
	printf("\nDigite o código do produto para inserção de estoque: ");
	scanf("%d",&codigo);
	for(x=0;x<sequencia;x++){
		if(produtos[x].codigo==codigo){
			printf("\nCódigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nEstoque atual: %d\n\n",produtos[x].estoque);
			printf("\nDigite a quantidade de entrada em estoque: ");
			scanf("%d",&estoque);
			produtos[x].estoque+=estoque;
			printf("\nEstoque atualizado com sucesso!\n");
			printf("\nNovo valor do estoque: %d\n",produtos[x].estoque);
			break;
		}else{
			printf("\nProduto não encontrado\n");
		}
	}
	system("pause");
}
ajusteEstoque(){
	system("cls");
	int codigo,x,estoque;
	printf("\nDigite o código do produto para ajuste de estoque: ");
	scanf("%d",&codigo);
	for(x=0;x<sequencia;x++){
		if(produtos[x].codigo==codigo){
			printf("\nCódigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nEstoque atual: %d\n\n",produtos[x].estoque);
			printf("\nDigite a quantidade para ajuste em estoque: ");
			scanf("%d",&estoque);
			produtos[x].estoque=estoque;
			printf("\nEstoque ajustado com sucesso!\n");
			printf("\nNovo valor do estoque: %d\n",produtos[x].estoque);
			break;
		}else{
			printf("\nProduto não encontrado\n");
		}
	}
	system("pause");
}
ajusteCadastro(){
	system("cls");
	int codigo,x,estoque;
	printf("\nDigite o código do produto para atualizar o cadastro: ");
	scanf("%d",&codigo);
	for(x=0;x<sequencia;x++){
		if(produtos[x].codigo==codigo){
			printf("\nCódigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nValor: %0.2lf",produtos[x].valorUnitario);
			printf("\nDigite o nome do produto: ");
			fflush(stdin);
			gets(produtos[x].nome);
			printf("\nDigite o valor unitário: ");
			scanf("%lf",&produtos[x].valorUnitario);
			printf("\nDados atualizados com sucesso!\n");
			break;
		}else{
			printf("\nProduto não encontrado\n");
		}
	}
	system("pause");
}
buscarProduto(){
	system("cls");
	int x,codigo;
	printf("\nDigite o codigo do produto que deseja: ");
	scanf("%d",&codigo);
	for(x=0;x<sequencia;x++){
		if(produtos[x].codigo==codigo){
			printf("\nCodigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nValor: %0.2lf",produtos[x].valorUnitario);
			printf("\nEstoque: %d\n",produtos[x].estoque);
			break;
		}else{
			printf("\nProduto não encontrado!\n");
		}
	}
	system("pause");
}
venda(){
	system("cls");
	int codigo,x,qtde,continuar,achou=0;
	double subtotal,total;
	do{
		printf("\nDigite o código do produto: ");
		scanf("%d",&codigo);
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\nCódigo: %d - Nome: %s - Valor Unitário: %0.2lf"
				,produtos[x].codigo,produtos[x].nome,produtos[x].valorUnitario);
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
		if(achou==0){
			printf("\nProduto não encontrado\n");
		}else{
			printf("\nDigite a quantidade: ");
			scanf("%d",&qtde);
			if(produtos[x].estoque>0 && qtde<=produtos[x].estoque){
				produtos[x].estoque-=qtde;
				subtotal=qtde*produtos[x].valorUnitario;
				total+=subtotal;
			}else{
				printf("\nSem produto em estoque\n");
				system("pause");
			return;
			}
		}
		printf("\nDeseja inserir mais algum produto: 1-sim 2-não:  ");
		scanf("%d",&continuar);
	}while(continuar!=2);
	if(achou!=0){
		printf("\n o total da compra foi de %0.2lf\n",total);
		printf("\nForma de pagamento: ");
		printf("\n1-dinheiro 2-credito: ");
		int pag;
		scanf("%d",&pag);
		if(pag==1){
			printf("\nPagamento em dinheiro, valor: R$%0.2lf\n",total);
		}else if(pag==2){
			total=total*1.03;
			printf("\nPagamento em cartão, valor total com acrescimo de 3%%: R$%0.2lf\n",total);
		}else{
			printf("\nforma de pagamento inválida");
		}
		vendas[nvendas]=total;
		nvendas++;
		system("pause");
	}
}
main(){
	setlocale(LC_ALL, "Portuguese");
	int x;
	do{
		system("cls");
		printf("\nDigite 1 para cadastrar um produto\nDigite 2 para dar entrada em estoque\nDigite 3 para ajustar um estoque\nDigite 4 para ajustar o cadastro\nDigite 5 para listar todos os produtos\nDigite 6 para buscar um produto por codigo\nDigite 7 para realizar uma venda\nDigite sua opção: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				cadastrarProduto();
			break;
			case 2:
				entradaEstoque();
			break;
			case 3:
				ajusteEstoque();
			break;
			case 4:
				ajusteCadastro();
			break;
			case 5:
				listarProdutos();
			break;
			case 6:
				buscarProduto();
			break;
			case 7:
				venda();
			break;
			case 8:
				listarVendas();
			break;
			default:
				printf("\nOpção inválida\n");
		}
	}while(x!=0);
	return 0;
}
