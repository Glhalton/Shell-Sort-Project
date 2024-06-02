#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int arr[] = {3, 7, 2, 9, 1, 10, 6, 8, 4, 5};

void shellSort(int *lista, int tamanho){


    float k=log(tamanho+1)/log(3); //Cálculo do número de varreduras

    k=floor(k+0.5); //Arredondamento Universal

    int h=(pow(3,k)-1)/2; //Cálculo da distância h para a primeira varredura

    //int h = 3; //tamanho do intervalo

    while(h>0){

        for(int i=0; i<tamanho-h; i++){

            // se indice da frente for menor que o indice de tras, realize a troca.
            if(lista[i]>lista[i+h]){ 

                int valor_menor = lista[i+h]; //armazena o indice do menor.
                lista[i+h] = lista[i]; //troca o indice do menor para o maior.
                lista[i] = valor_menor; //troca o indice do maior para o menor.

                int j = i-h;//índice para verificar de os valores anteriores são maiores que o atual.
                while(j>=0){

                    if(valor_menor<lista[j]){

                        lista[i] = lista[j]; //troca o valor_menor que está o indice i para o valor maior.
                        lista[j] = valor_menor;//troca o valor_maior que está no índice j para o valor menor.

                    }else{break;}
                    j=j-h;//verifica índices anteriores.
                }

            }

        } h -= 1;

    }

}
int main(){

    shellSort(arr, 10);
    for(int m = 0; m<10; m++){

        printf("\n%d", arr[m]);

    }

    return 0;
}