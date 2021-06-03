/**
 * 
 * @author Nelson Alexandre Mutane
 * @Licence MIT
 *   
 **/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Estrutira basica de uma S-L-List
typedef struct No
{
	int elemento;
	struct No *prox; //ponteiro que aponta ao proximo elemento.
}No;

/**
 * funcao que cria um novo no simples com um elemento.
 * @param int elemento
 * @return No*
 **/
No *novoNo(int elemento){
	No *aux = (No*) malloc(sizeof(No));
	aux->elemento = elemento;
	aux->prox = NULL;
	return aux;
}

/**
 * Funcao que adiciona novo elemento na lista.
 * @param No *lista
 * @param int elemento 
 * @return No* 
 * 
 **/
No *adicionarElemento(No *lista,int elemento){
	No *aux = lista;
	   if(aux == NULL){
		   return novoNo(elemento);
	   }else{
		   aux->prox  = adicionarElemento(aux->prox,elemento);
	   }
	 return aux;	
}

/**
 * Funcao de imprimir todos elementos de uma lista.
 * @param No *lista
 * @return void
 **/
void imprimirLista(No *lista );

/**
 * Funcao de editar elemento que estiver na posicao selecionada
 *@param No *lista
 *@param int posicao
 *@param int novoElemento
 *@return void
 **/
void  editarPorPosicao(No *lista,int posicao, int novoElemento){
	if(posicao == 0 && lista != NULL){
		lista->elemento = novoElemento;
		posicao = -1;
	}else if(posicao > -1 && lista != NULL){
		editarPorPosicao(lista->prox,--posicao,novoElemento);
	}else
	printf("Posicao invalida \n",posicao);
}

/**
 * Funcao de editar  todos elementos que forem iguais ao elemento dado
 *@param No *lista
 *@param int elementoPorComparar
 *@param int novoElemento
 *@return void
 * */
void editarPorComparacao(No *lista,int elementoPorComparar,int novoElemento){
		if(lista != NULL){
			
			if (lista->elemento == elementoPorComparar)
			{
				lista->elemento = novoElemento;
			}
			editarPorComparacao(lista->prox,elementoPorComparar,novoElemento);
		}else 
		{
			printf("Elemento nao encontrado");
		}
}

/**
 * Funcao de deleta  todos elementos que forem iguais ao elemento dado
 *@param No *lista
 *@param int inicio
 *@param int posicao
 *@return No*
 * */
No *deletarPorComparacao(No *lista, int elementoPorComparar){
	No *aux = lista;
	if(aux != NULL){
		if(aux->prox == NULL && aux->elemento == elementoPorComparar){
			return NULL;
		}else if(aux->elemento == elementoPorComparar){
			aux->elemento = aux->prox->elemento;
			aux->prox = aux->prox->prox;
		}else{
			 aux->prox = deletarPorComparacao(aux->prox ,elementoPorComparar);
		}
	}
	return aux;
}

/**
 * Funcao de deleta o elemento da posicao dada.
 *@param No *lista
 *@param int inicio
 *@param int posicao
 *@return No*
 * */
No *deletarPorPosicao(No *lista, int inicio, int posicao){
	No *aux = lista;
	printf("[ %i ]",inicio);
	if(aux != NULL){
		if(aux->prox == NULL && inicio == posicao){
			return NULL;
		}else if(inicio == posicao){
			aux->elemento = aux->prox->elemento;
			aux->prox = aux->prox->prox;
		}else{
			 aux->prox = deletarPorPosicao(aux->prox ,++inicio,posicao);
		}
	}
	return aux;
}

void imprimirLista(No *lista ){
	   struct No *aux  = lista;
	   while(aux!=NULL){
		   printf(" {%i}, ",aux->elemento);
		   aux = aux->prox;
	   }	
}


int main(int argc, char const *argv[])
{/**	
	struct No *teste = NULL;
teste =	adicionarElemento(teste,0);
size_t i;
for ( i = 1; i < 10; i++)
{
	adicionarElemento(teste,i);
}
	deletarPorPosicao(teste,0,9);
	imprimirLista(teste);
	//printf("hello word"); **//   
    return 0;
}
