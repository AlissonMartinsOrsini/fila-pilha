#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "fila.h"


typedef TipoAluno TipoDadoPilha; //Define o tipo de dado que será armazenado na Pilha


//Essa estrutura será utilizada como uma célula da Pilha
//Item armazena o valor informado pelo usuário
//Prox é um ponteiro que aponta para outra célula da Pilha
//Esse ponteiro será utilizado para apontar para a célula que contém o próximo
//valor a ser desempilhado na Pilha (a célula que está "abaixo" da atual)
struct TipoCelulaPilha{

   TipoDadoPilha Item;
   TipoCelulaPilha *Prox;
};


//Um construtor é um método que deve ser executado obrigatoriamente antes da pilha ser utilizada
void Pilha_Construtor();

void Pilha_Construtor2();


//Método para recuperar a memória dinâmica alocada para a Pilha
//Ao contrário de um construtor, o destrutor é um método que deve ser executado
//depois da pilha ser utilizada
void Pilha_Destrutor();
void Pilha_Destrutor2();

//Função para indicar se a Pilha está ou não vazia (se exite ou não algum elemento armazenado)
bool Pilha_Vazia();
bool Pilha_Vazia2();

//Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha_Tamanho();
int Pilha_Tamanho2();

//Método para adicionar elementos do topo da Pilha
//Se o elemento for Empilhado (armazenado na Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//Esse método também é conhecido como Push
bool Pilha_Empilhar(TipoDadoPilha expressao);
bool Pilha_Empilhar2(TipoDadoPilha expressao);

//Método para remover elementos da Pilha
//Se o elemento for Desempilhado (removido da Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//O Elemento no topo da Pilha é removido e retornado por referência pelo parâmetro da função
//Esse método também é conhecido como Pop
bool Pilha_Desempilhar(TipoDadoPilha &Elemento);
bool Pilha_Desempilhar2(TipoDadoPilha &Elemento);
//Método para retornar o elemento no topo da Pilha sem removê-lo
//O elemento é retornado por referência pelo parâmetro da função
bool Pilha_Topo(TipoDadoPilha &Elemento);
bool Pilha_Topo2(TipoDadoPilha &Elemento);


#endif // PILHA_H_INCLUDED


