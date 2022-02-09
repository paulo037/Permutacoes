#include "permutacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void inicializaLista(Celula ***lista, int N){
    (*lista) = (Celula **) malloc(sizeof(Celula*) * N);
    for (int i = 0; i < N; i++){
        (*lista)[i] = (Celula*) malloc(sizeof(Celula));
        (*lista)[i]->situacao = Desmarcada; 
    }
}

void permutar(Celula ***lista,
                int N, 
                int pos, 
                char array[], 
                char** permutacoes, 
                int* j){ 
                           
                           

    //Parametros auxiliares
    char buffer[TAM_MAX];  

    for (int i = 0; i < N; i++){
        if((*lista)[i]->situacao == Desmarcada){
                
                //Faz uma copia do array atual para não se perder o valor
                strcpy(buffer,  array);
                //concatena o array atual com a cidade da iteração. EX: '12' + '3'
                strcat(buffer, (*lista)[i]->nome);
                //Guarda o valor do novo array no resultado
                strcpy(permutacoes[(*j)],  buffer );
                (*j)++;
                //Incrementa o array que guarda as posições
              
            //se tiver poições não percorridas, marca a posição atual e faz a chamada recursiva
            if (pos < N -1){
                (*lista)[i]->situacao = Marcada;
                permutar(lista, N, pos + 1, buffer, permutacoes, j);
                (*lista)[i]->situacao = Desmarcada;
            }
        
        }
    }
}

