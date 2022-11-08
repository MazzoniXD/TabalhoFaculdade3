#include <stdio.h>
#include <stdlib.h>

// Struct para cada número inserido
typedef struct no{
	int valor;
	struct no *esquerda, *direita;
}No;

// Struct para Determinar a Árvore
typedef struct{
	No *raiz;
}Arv;

int main(){
	int numero, continua, altE, altD, tesE, tesD;
	Arv arv;
	arv.raiz = NULL;
	continua = 1;
	altE = 0;
	altD = 0;

	printf("BEM-VINDO NO TESTE DE ALTURA DA ARVORE!!!\n");

	do{
		// Posição para digitar o número
		printf("\nPor favor, digitar um numero.\n");
		printf("Resposta: ");
		scanf("%d", &numero);
		fflush(stdin);
		
		// Vai para direção da função Inserir
		// Verificando se a altura está aumentando
		if(arv.raiz == NULL)
			inserir(numero, &arv);
		else if(numero < arv.raiz->valor){
			tesE = inserir(numero, &arv);
			if(altE < tesE)
				altE = tesE;
		}else{
			tesD = inserir(numero, &arv);
			if(altD < tesD)
				altD = tesD;
		}

		// Pergunta se vai continuar colocando números
		printf("\nVoce quer adicionar mais algum numero?\n");
		printf("1 - Sim\n");
		printf("2 - Nao\n");
		printf("Resposta: ");
		scanf("%d", &continua);
	}while (continua != 2);

	// Aqui é para testar o resultado da árvore
	// Fazer em código uma forma de contar a Altura
	if(altE-altD == 0 || altE-altD == -1 || altE-altD == 1)
		printf("E uma AVL!!!");
	else
		printf("Nao e AVL!!!");
	
	free(arv.raiz);
	return (0);
}

// Função de Inserir na Árvore
int inserir(int numero, Arv *arv){
	int passos;
	passos = 0;

	// Verifica se a Raiz está Vazia
	if(arv->raiz == NULL){
		No *inserido = (No*)malloc(sizeof(No));
		inserido->valor = numero;
		inserido->esquerda = NULL;
		inserido->direita = NULL;
		arv->raiz = inserido;
	}else
		if(numero < arv->raiz->valor)
			passos = inserirEsquerda(arv->raiz, numero, passos);
		else
			passos = inserirDireita(arv->raiz, numero, passos);

		return passos;
}

// Função para Inserir na Direção da Esquerda
int inserirEsquerda(No *no, int numero, int passos){
	passos++;
	// Verifica se na Esquerda está Vazia
	if(no->esquerda == NULL){
		No *inserido = (No*)malloc(sizeof(No));
		inserido->valor = numero;
		inserido->esquerda = NULL;
		inserido->direita = NULL;
		no->esquerda = inserido;
	}else
		if(numero < no->esquerda->valor)
			passos = inserirEsquerda(no->esquerda, numero, passos);
		else
			passos = inserirDireita(no->esquerda, numero, passos);
		
		return passos;
}

// Função para Inserir na Direção da Direita
int inserirDireita(No *no, int numero, int passos){
	passos++;
	// Verifica se na Direita está Vazia
	if(no->direita == NULL){
		No *inserido = (No*)malloc(sizeof(No));
		inserido->valor = numero;
		inserido->esquerda = NULL;
		inserido->direita = NULL;
		no->direita = inserido;
	}else
		if(numero < no->direita->valor)
			passos = inserirEsquerda(no->direita, numero, passos);
		else
			passos = inserirDireita(no->direita, numero, passos);
		
		return passos;
}
