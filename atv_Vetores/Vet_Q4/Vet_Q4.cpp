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

int main(){

    int vetorzao[10]; // somente p/ testar a funçao, pode apagar

    for (int i=0; i<10; i++){ // tb p/ testar, pode apagar
        int a;
        scanf("%d", &a);
        vetorzao[i] = a;
    }
    vet_q4(vetorzao, 10); // tb p/ testar pode apagar

    return 0;
}