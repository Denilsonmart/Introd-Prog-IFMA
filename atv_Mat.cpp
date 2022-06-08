#include <cstdlib>
#include <stdio.h>

void vet_q4(int *vetorzao, int tamVetorzao){ // passar como parametros o vetorzao e o tamanho dele
    int maior = vetorzao[0], menor = vetorzao[0], nPares=0, nImpares=0;

    for(int i=1; i<tamVetorzao; i++){
        if (maior < vetorzao[i]) // Comparação de um elemento com o próximo p/ saber qual o maior
            maior = vetorzao[i];
        if (menor > vetorzao[i]) // comparação de um elemento com o próximo p/ saber qual o menor
            menor = vetorzao[i];
        if (vetorzao[i-1]%2 == 0) // verifica se é par ou impar
            nPares++; // caso seja par incrementar o contador de nº pares
        else
            nImpares++; // caso contrario incrementa o contador de nº ímpares
    }
    printf("O maior eh %d e o menor eh %d, tem %d numeros pares e %d impares\n", maior, menor, nPares, nImpares);
}

void printM(int **m, int qtdLinhas, int qtdColunas){
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int** alocaM(int **m, int qtdLinhas, int qtdColunas){

    m = (int**)calloc(qtdLinhas, sizeof(int*));

    for (int i = 0; i < qtdLinhas; i++) {
        m[i] = (int*)calloc(qtdColunas, sizeof(int));
    }

    return m;
}

void lerMatriz(int **m, int qtdLinhas, int qtdColunas){

    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            int val;
            printf("Digite o valor do elemento [%d][%d]: ", i, j);
            scanf("%d", &val);
            m[i][j] = val;
        }
    }

}

typedef struct Matriz{
    int **m;
    int qtdLinhas;
    int qtdColunas;

} Matriz;

int main(){
    int qtd;

    printf("Quantas matrizes você quer?\n");
    scanf("%d", &qtd);

    Matriz m[qtd];

    for (int i = 0; i < qtd; i++) {
        printf("Matriz %d:\n", i);

        printf("Quantas linhas nessa budega? ");
        scanf("%d", &(m[i].qtdLinhas));
        printf("Quantas colunas nessa budega? ");
        scanf("%d", &(m[i].qtdColunas));

        m[i].m = alocaM(m[i].m, m[i].qtdLinhas, m[i].qtdColunas); // alocação da matriz na struct
        //lerMatriz(m[i].m, m[i].qtdLinhas, m[i].qtdColunas);
    }

    printf("\n---IMPRIMINDO AS MATRIZES---\n");

    for (int i = 0; i < qtd; i++) { // Fazer a impressão das matrizes
        printf("\n");
        printM(m[i].m, m[i].qtdLinhas, m[i].qtdColunas);
    }

    return 0;

}






