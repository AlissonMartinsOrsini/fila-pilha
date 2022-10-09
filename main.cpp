/*
Alisson Martins Orsini

O objetivo do progama é pegar do usuario uma matricula e uma nota independente da ordem das matriculas e ordenar em uma pilha pelas notas:

A entrada de dados devera ser feita por um usuario perfeito. por exemplo. sem espaчos e somente numeros inteiros para a matricula e notas

como resultado o progama tem a pilha de forma que o topo é a maior nota, e a menor nota esta por baixo.

*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"


using namespace std;

int main()
{

    Fila_Construtor(); //inicia a fila
    Pilha_Construtor(); // inicia a pilha 1
    Pilha_Construtor2(); // inicia a pilha 2 que vai auxiliar na ordencao das notas

    TipoAluno Aluno; // tipoaluno é um inteiro, aluno é uma varivael que vai auxiliar na coleta de dados



    char controle; // variavel que controla o final do  do-while
    TipoAluno topo, topo2, frenteFila; // topo para pilha 1, topo2 para pilha dois e frente para pilha
    cout << "Progama que controla as notas dos alunos\n" ;

    do   //menu com opções para testar a implementação da Fila Dinâmica
    {

        cout << "\nEntre com Matricula: " ;
        cin >> Aluno.matricula; // pega a matricula
        cout << "Entre com a nota: ";
        cin >> Aluno.nota; // pega a nota
        //cout <<"\n";

        if(Fila_Enfileirar(Aluno))   //Tenta armazenar na fila
        {
            printf("\nElemento armazenado na Fila\n");// confirma quando armazenado
        }

        else printf("Erro: Nao ha memoria disponivel\n\n"); //  avisa se nao armazenar

        cout << "\nDeseja sair? S/N\n"; // confirma com o usuario se continua ou nao no do-while
        cin >> controle;


    }
    while(controle != 's' && controle != 'S');  // teste para sair do do-while


    // apos esse do-while temos a certeza que a fila esta do jeito que o usuario quis
    // entao precisamos empilhar esses dados ordenando

    //cout << "saiu do while\n" ;
    while (!Fila_Vazia()) // confere se a fila esta vazia para rodar somente enquanto tiver dados na fila
    {
        Fila_Frente(frenteFila); // chama a funcao passando um frentefila que a funcao é somente pegar por referencia a frente da fila que a funcao devolve

        if (!Pilha_Vazia())  // verifica se a pilha ta viazia
        {

            Pilha_Topo(topo); // chama a funcao e passa a variavel vazia para conseguir saber por referencia qual é o topo nesse momento

            if (frenteFila.nota > topo.nota) // se a nota que esta na fila for maior q esta no topo entra
            {

                Fila_Desenfileirar(frenteFila);// é desenfileirado
                Pilha_Empilhar(frenteFila); // e empilhado

            }

            else if(frenteFila.nota < topo.nota) // caso essa nota que esta na frente da fila for menor que a nota do topo entra e
            {



                while(!Pilha_Vazia() && frenteFila.nota < topo.nota) // roda nesse while para saber ate quando essa nota é menor
                {

                    Pilha_Empilhar2(topo);  // empilha na pilha dois
                    Pilha_Desempilhar(topo); // desempilha da pilha um

                    Pilha_Topo(topo); // como é um while eu preciso chamar essa funcao para depois que eu desempilhar eu saber quem é o topo para
                    // ter o controle de que estou com o topo certo



                }


                Fila_Desenfileirar(frenteFila); // quando sai do while eu tenho que empilhar o que esta na fila
                Pilha_Empilhar(frenteFila); // entao eu desinfilero e empilho e rodo o while

                while(!Pilha_Vazia2()) // esse while vai esvaziar a pilha dois voltando com os dados para a pilha dois
                {
                    Pilha_Desempilhar2(topo2); // desempilha da pilha 2
                    // e
                    Pilha_Empilhar(topo2);  // empilha na pilha um

                } //  ele roda enquanto a pilha2 tiver dados ou seja, esvazia a pilha dois e coloca na pilha1

            }
            else//(Fila_Frente(Aluno) == Pilha_Topo(Aluno)) entra nesse else quando a condicao é a comentada ao lado
            {
                // quando a nota for igual a matricula sera o desempate,
                if (frenteFila.matricula < topo.matricula)   // testa qual matricula é maior , no caso de empate das notas as matriculas serao comparadas e a menor vai na frente
                {
                    Pilha_Empilhar(frenteFila);
                    Fila_Desenfileirar(frenteFila);
                }
                else // se a matricula que esta na fila for maior que a do topo
                {
                    while(!Pilha_Vazia() && frenteFila.nota==topo.nota && frenteFila.matricula > topo.matricula) // se a nota for igual e a matricula da fila for maior que a do topo esse while roda
                    {

                        Pilha_Desempilhar(topo2); //fazendo com que o elemento saia da pilha1 e vai para a pilha2
                        Pilha_Empilhar2(topo2); //
                        Pilha_Empilhar(frenteFila);//
                        Fila_Desenfileirar(frenteFila);// depois de desempilhar da pilha1, empilhar na pilha2
                        Pilha_Topo(topo); // chamada de controle para saber quem é o topo do momento
                        Fila_Frente(frenteFila); // chamada de controle para saber quem é a frente do momento

                        while(!Pilha_Vazia2()) // esse while vai esvaziar a pilha dois voltando com os dados para a pilha dois
                        {
                            Pilha_Desempilhar2(topo2); // desempilha da pilha 2
                            // e
                            Pilha_Empilhar(topo2);  // empilha na pilha um

                        } //  ele roda enquanto a pilha2 tiver dados ou seja, esvazia a pilha dois e coloca na pilha1
                    }

                }

            }
        }


        else
        {
            Pilha_Empilhar(frenteFila); // empilha o primeiro numero
            Fila_Desenfileirar(frenteFila); // e desinfileira
            // e a proxima vez a pilha ja nao esta vazia e entra no if la de cima
        }
    }




    while (!Pilha_Vazia()) // while serve para mostrar a pilha para o usuario
    {
        Pilha_Topo(topo);//chama o topo para saber quem é
        Pilha_Desempilhar(topo);// desempilha ele
        cout << "\npilhas de notas |" << topo.nota << "| matricula |" << topo.matricula << "|";// como eu sei quem é o topo e topo
        // é uma variavel do tipo aluno eu consigo mostrar dessa forma para o usuario
    }

    cout << "\n\n";
    return 0;
}
