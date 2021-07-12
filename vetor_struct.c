#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 8

typedef struct Barraca {
    char nome;                                                
    int vendas;                         
} barracas;

barracas lista[tamanho];
barracas aux[tamanho];

void cabecalho(void);
void menu_aluno(void);
void inserir_barracas();
void menu_mostrar(void);
void mostrar_barraca(void);
void mergeSort(barracas lista[], int baixo, int topo );
void merge_junta(barracas lista[], int baixo, int meio, int topo);
	
int main(){
	int op=-1;		
	setlocale(LC_ALL,"Portuguese");	
	inserir_barracas();
	menu_aluno();
	system("pause");
	
	do{
		system("cls");
		system("color 07");
		cabecalho();
		mostrar_barraca();
		menu_mostrar();
		scanf("%d",&op);
		
		switch (op){
			case 1:
				mergeSort(lista,0,tamanho-1);	
				system("cls");
				menu_aluno();
				printf("Aplicando o MergeSort. Por favor aguarde...\n\n");
				system("color 03");
				system("pause");
			break;
			
			default:
				if(op != 0){
					system("cls");
					system("color 4f");
					printf("Opção inválida.\n");
					system("pause");
				}
			break;
		}
	}while(op!=0);
	printf("\n\nSaindo, por favor aguarde...\n");
	system("pause");
	return(0);	
}

void cabecalho(void){
	printf(">>>>>>>>>>>>>>>>>>>>>>Sistema da relação diaria de vendas<<<<<<<<<<<<<<<<<<<<<<<");
	printf("\t\n\t\t\t\tFeira do São Brás\n\n");
}

void menu_aluno(void){
	printf("********************************************************************************");
	printf("Aluno:Lucas Vinícius Sampaio Lima\t\t\t\tR.A:20026518-5\nFaculdade:Bacharelado em Engenharia de Software");
	printf("\n********************************************************************************\n\n\t\tMAPA - ESOFT - ESTRUTURA DE DADOS II - 52/2021\n\n");
}

void inserir_barracas(){
	lista[0].vendas=2;
 	lista[1].vendas=0;
	lista[2].vendas=0;
	lista[3].vendas=2;
	lista[4].vendas=6;
	lista[5].vendas=5;
	lista[6].vendas=1;
	lista[7].vendas=8;
	
	lista[0].nome='A';
	lista[1].nome='B';
	lista[2].nome='C';
	lista[3].nome='D';
	lista[4].nome='E';
	lista[5].nome='F';
	lista[6].nome='G';
	lista[7].nome='H';
}

void menu_mostrar(void){
	printf("\nMENU\n\n\t1-Aplicar com Mergesort\n\t0-Sair...\n\nEscolha Uma Opção: ");	
}

void mostrar_barraca(void){
	printf("Lista das Barracas com suas respectivas vendas:\n\n");
	 printf("\t|Barracas | Vendas Diarias |\n");
    for (int i = 0;  i < tamanho;  ++i)
    printf("\t|   %c \t  |\t  %d\t   |\n",lista[i].nome,lista[i].vendas);
    printf("-------------------------------------------\n");
}

void mergeSort(barracas lista[], int baixo, int topo ){
    int meio = (topo + baixo) / 2;
    if (topo <= baixo)
    	return;
    mergeSort(lista, baixo, meio);
    mergeSort(lista, meio + 1, topo);
    merge_junta(lista, baixo, meio, topo);
}

void merge_junta(barracas lista[], int baixo, int meio, int topo){
   
    
    int k=0, i,esquerda=baixo, direita = meio + 1;

    for (;  (esquerda <= meio) && (direita <= topo);  ++k) {
        if (lista[esquerda].vendas <= lista[direita].vendas)
            aux[k] = lista[esquerda++];
        else
            aux[k] = lista[direita++];
    }

    for (;esquerda <= meio;  ++esquerda, ++k)
        aux[k] = lista[esquerda];

    for (;  direita <= topo;  ++direita, ++k)
        aux[k] = lista[direita];

    k = baixo;
    i = 0;
    for (;k <= topo;  ++k, ++i)
    lista[k] = aux[i]; 
}
