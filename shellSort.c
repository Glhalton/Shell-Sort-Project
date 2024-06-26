#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Estrutura dos Dados: DADOS BANCARIOS

typedef struct dados Dados;

struct dados{
    char nome[30];
    int numero;
    float saldo;
    Dados *proximo;

};

//Função para adicionar no INICIO da lista

void inserirNoInicio(Dados **lista, char novoNome[], int novoNumero , float novoSaldo){
    Dados *novo;
    novo = (Dados *)malloc(sizeof(Dados));
    strcpy(novo->nome, novoNome);
    novo->numero = novoNumero;
    novo->saldo = novoSaldo;
    novo->proximo = *lista;
    *lista = novo;

}

//Função para adicionar no FINAL da lista

void inserirNoFinal(Dados **lista, char novoNome[], int novoNumero , float novoSaldo){
    Dados *novo;
    Dados *aux;
    aux = (Dados *)malloc(sizeof(Dados));
    novo = (Dados *)malloc(sizeof(Dados));
    strcpy(novo->nome, novoNome);
    novo->numero = novoNumero;
    novo->saldo = novoSaldo;
    novo->proximo = NULL;
    if(*lista == NULL){
        *lista = novo;
    } else{
        aux = *lista;
        while(aux->proximo){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }

}

//Função para IMPRIMIR a lista

void imprimir (Dados *dados){
    printf("\n----------------Dados Bancarios----------------\n");
    while(dados){
        printf("\nNome: %s\nNumero: %d\nSaldo: %2.f\n", dados->nome, dados->numero, dados->saldo);
        dados = dados->proximo;
    }

}

//Função de ORDENAÇÃO utilizando SHELL SORT
 
void shellSort(float *listaOrdenada, int tamanho){

    float k=log(tamanho+1)/log(3); //Cálculo do número de varreduras

    k=floor(k+0.5); //Arredondamento Universal

    int h=(pow(3,k)-1)/2; //Cálculo da distância h para a primeira varredura

    //int h = 3; //tamanho do intervalo

    while(h>0){

        for(int i=0; i<tamanho-h; i++){

            // se indice da frente for menor que o indice de tras, realize a troca.
            if(listaOrdenada[i]>listaOrdenada[i+h]){ 

                int numero_menor = listaOrdenada[i+h]; //armazena o indice do menor.
                listaOrdenada[i+h] = listaOrdenada[i]; //troca o indice do menor para o maior.
                listaOrdenada[i] = numero_menor; //troca o indice do maior para o menor.

                int j = i-h;//índice para verificar de os numeroes anteriores são maiores que o atual.
                while(j>=0){

                    if(numero_menor<listaOrdenada[j]){

                        listaOrdenada[i] = listaOrdenada[j]; //troca o numero_menor que está o indice i para o numero maior.
                        listaOrdenada[j] = numero_menor;//troca o numero_maior que está no índice j para o numero menor.

                    }else{break;}
                    j=j-h;//verifica índices anteriores.
                }

            }

        } h -= 1;

    }

}

int tamanho; // tamanho do array

int main(){

    int opcao;
    char nome[30];
    int numero;
    float saldo;

    Dados *lista = NULL;

    do{
        printf("\n----------------ESCOLHA UMA OPCAO----------------\n[1] - Inserir no Inicio\n[2] - Inserir no Final\n[3] - Imprimir Dados\n[4] - Ordenar por saldo\n[5] - Sair\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("\n>>> Digite o Nome: ");
                scanf("%s",nome);
                fflush(stdin);
                printf("\n>>> Digite o Numero: ");
                scanf("%d",&numero);
                printf("\n>>> Digite o Saldo: ");
                scanf("%f",&saldo);
                inserirNoInicio(&lista, nome, numero, saldo);
                tamanho += 1;
                break;

            case 2:
                printf("\n>>> Digite o Nome: ");
                scanf("%s",nome);
                fflush(stdin);
                printf("\n>>> Digite o Numero: ");
                scanf("%d",&numero);
                printf("\n>>> Digite o Saldo: ");
                scanf("%f",&saldo);
                inserirNoFinal(&lista, nome, numero, saldo);
                tamanho += 1;
                break;

            case 3:
                imprimir(lista);
                break;

            case 4:{
                float *arr = (float *)malloc(tamanho * sizeof(float));
                Dados *aux5 = lista;
                if(tamanho > 0){
                    for (int i = 0; i < tamanho; i++){
                        arr[i] = aux5->saldo;
                        printf("\nValor no indice(%d): %f", i, arr[i]);
                        aux5 = aux5->proximo;

                    }
                }

                shellSort(arr, tamanho);

                printf("\n----------------EXIBINDO LISTA ORDENADA----------------");
                for(int m = 0; m<tamanho; m++){
                    printf("\n%.2f", arr[m]);
                }
                break;
            }
            case 5:
                break;

            default:
                if(opcao != 0){
                    printf("Opcao Invalida!\n");
                }
        }

    }while(opcao != 5);

    return 0;
}