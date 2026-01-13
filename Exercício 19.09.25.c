#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//variaveis
int op,N,N2,quant[10],achou = 0,quantOp[10],id,k = 1,antes[10];
float preco[10],total[10];
char prod[10][20],op2,nome[10][20],prodOp[10][20];


void cadastro()
{

    printf("Quantos produtos voce quer inserir:\n");
    scanf("%d",&N);
    while(getchar()!= '\n');
    fflush(stdin);
    for(int i = 1; i<=N; i++)
    {
        printf("Insira o produto %d:\n",i);
        fgets(prod[i],20,stdin);
        fflush(stdin);
        printf("Qual a quantidade desse produto no estoque ?:\n");
        scanf("%d",&quant[i]);
        antes[i] = quant[i];
        fflush(stdin);
        printf("Qual o valor do produto?(inserir somente numero):\n");
        scanf("%f",&preco[i]);
        fflush(stdin);
        while(getchar()!= '\n');
        system("cls");
    }
}
void consulta()
{
    for(int j = 1; j<=N; j++)
    {
        printf("Produto: %s \n",prod[j]);
        printf("Quantidade: %d \n",quant[j]);
        printf("Preco: %.2f \n",preco[j]);
    }
    system("pause");
    system("cls");
}
void baixa()
{
    printf("Qual o nome do cliente ?:\n");
    fgets(nome[k],20,stdin);
    fflush(stdin);
    do
    {
        printf("Qual o produto que deseja?:\n");
        fgets(prodOp[k],20,stdin);
        fflush(stdin);
        achou=0;
//for que verifica se o produto existe no estoque
        for(int f=1; f<=N; f++)
        {
            if(strcmp(prodOp[k],prod[f])==0)
            {
                printf("Produto encontrado no estoque.\n");
                id = f;
                achou=1;
            }
        }
        if(achou == 1)
        {
            printf("Insira a quantidade que deseja deste produto:\n");
            scanf("%d",&quantOp[k]);
            fflush(stdin);
            if(quantOp[k]<=quant[id])
            {
                quant[id] = quant[id]-quantOp[k];
                total[k] = preco[id]*quantOp[k];
                printf("O total desta compra foi: %.2f\n",total[k]);
                k++;
            }
            else
            {
                printf("Quantidade acima do disponivel\n");
            }
        }
        if(achou == 0)
        {
            printf("Este produto nao esta no estoque");
        }
        printf("Voce deseja comprar mais algum produto?(S/N):\n");
        scanf(" %c",&op2);
        while(getchar()!= '\n');
        fflush(stdin);
        op2 =toupper(op2);
    }
    while(op2!= 'N');
}
void relatorio()
{
    for(int i = 1; i<k; i++)
    {
        printf("\nCliente: %s\n",nome[i]);
        printf("\nComprou: %d do produto %s\n",quantOp[i],prodOp[i]);
        printf("\nO total foi: %.2f\n",total[i]);
    }
}
void relatstok()
{
    for(int i = 1; i<=N; i++)
    {
        printf("\nO produto %s diminuiu de %d para %d\n",prod[i],antes[i],quant[i]);
    }
}
int main ()
{
    do
    {
        printf(" [1] Cadastro de Produtos\n [2] Consulta de Produtos\n [3] Baixa/Vendas\n [4] Relatorio de Saida\n [5] Relatorio de Produto/Estoque\n [6] Sair\n");
        scanf("%d",&op);
        while(getchar()!= '\n');
        fflush(stdin);
        system("cls");
        switch(op)
        {
        case 1:
            cadastro();
            break;
        case 2:
            consulta();
            break;
        case 3:
            baixa();
            break;
        case 4:
            relatorio();
            break;
        case 5:
            relatstok();
            break;
        case 6:
            return 0;
            break;
        }
    }
    while(op != 6);
}
