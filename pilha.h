#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "fila.h"


typedef TipoAluno TipoDadoPilha; //Define o tipo de dado que ser� armazenado na Pilha


//Essa estrutura ser� utilizada como uma c�lula da Pilha
//Item armazena o valor informado pelo usu�rio
//Prox � um ponteiro que aponta para outra c�lula da Pilha
//Esse ponteiro ser� utilizado para apontar para a c�lula que cont�m o pr�ximo
//valor a ser desempilhado na Pilha (a c�lula que est� "abaixo" da atual)
struct TipoCelulaPilha{

   TipoDadoPilha Item;
   TipoCelulaPilha *Prox;
};


//Um construtor � um m�todo que deve ser executado obrigatoriamente antes da pilha ser utilizada
void Pilha_Construtor();

void Pilha_Construtor2();


//M�todo para recuperar a mem�ria din�mica alocada para a Pilha
//Ao contr�rio de um construtor, o destrutor � um m�todo que deve ser executado
//depois da pilha ser utilizada
void Pilha_Destrutor();
void Pilha_Destrutor2();

//Fun��o para indicar se a Pilha est� ou n�o vazia (se exite ou n�o algum elemento armazenado)
bool Pilha_Vazia();
bool Pilha_Vazia2();

//Fun��o para retornar a quantidade de elementos armazenados na Pilha
int Pilha_Tamanho();
int Pilha_Tamanho2();

//M�todo para adicionar elementos do topo da Pilha
//Se o elemento for Empilhado (armazenado na Pilha), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//Esse m�todo tamb�m � conhecido como Push
bool Pilha_Empilhar(TipoDadoPilha expressao);
bool Pilha_Empilhar2(TipoDadoPilha expressao);

//M�todo para remover elementos da Pilha
//Se o elemento for Desempilhado (removido da Pilha), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//O Elemento no topo da Pilha � removido e retornado por refer�ncia pelo par�metro da fun��o
//Esse m�todo tamb�m � conhecido como Pop
bool Pilha_Desempilhar(TipoDadoPilha &Elemento);
bool Pilha_Desempilhar2(TipoDadoPilha &Elemento);
//M�todo para retornar o elemento no topo da Pilha sem remov�-lo
//O elemento � retornado por refer�ncia pelo par�metro da fun��o
bool Pilha_Topo(TipoDadoPilha &Elemento);
bool Pilha_Topo2(TipoDadoPilha &Elemento);


#endif // PILHA_H_INCLUDED


