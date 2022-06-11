#include <cstdlib>
#include <stdio.h>

/* Obs: em todas as estruturas de repetição considere "i" como indice da matriz, "l"linha e "c" como coluna,
ex: matriz[i].valor[l][c], lê-se valor da matriz número i na linha l coluna c */

typedef struct matriz{
    int **valor; // Onde será guardado os valores da matriz
    int qtdLinhas; // Vulgo qntd de vetores
    int qtdColunas; // Vulgo tamanho dos vetores

} Matriz;

void lerMatrizes(Matriz *matriz, int qtdMatrizes){ // Função p/ preencher a matriz com dados do usuário

    for (int i = 0; i < qtdMatrizes; i++) { // Percorre o vetor de matrizes
        printf("\n---PREENCHER MATRIZ %d---\n\n", i);
        for (int l = 0; l < matriz[i].qtdLinhas; l++) { // Percorre as matrizes armazenadas
            for (int c = 0; c < matriz[i].qtdColunas; c++) {
                int val;
                printf("Digite o valor do elemento [%d][%d]: ", l, c);
                scanf("%d", &val);
                matriz[i].valor[l][c] = val; // Faz a atribuição do valor dado pelo usuário p/ a matriz
            }
        }
    }
}

Matriz* alocaAllM(Matriz *matriz, int qtdMatrizes){

    matriz = (Matriz*)calloc(qtdMatrizes, sizeof(Matriz)); // Alocar o vetor de matrizes

    for (int i = 0; i < qtdMatrizes; i++) { // Percorre o vetor de matrizes
        printf("Matriz %d:\n", i);
        printf("Quantas linhas nessa budega? ");
        scanf("%d", &(matriz[i].qtdLinhas)); // Faz a atribuição das linhas de cada matriz no vetor
        printf("Quantas colunas nessa budega? ");
        scanf("%d", &(matriz[i].qtdColunas)); // Faz a atribuição das coluans de cada matriz no vetor

        matriz[i].valor = (int**)calloc(matriz[i].qtdLinhas, sizeof(int*)); // Aloca as matrizes que estão dentro do vetor
        for (int l = 0; l < matriz[i].qtdLinhas; l++) { // Percorre as linhas das matrizes armazenadas dentro do vetor
            matriz[i].valor[l] = (int*)calloc(matriz[i].qtdColunas, sizeof(int)); // Aloca as linhas (vetores) das matrizes armazenadas
        }
    }
    return matriz; // Retorna o vetor de matrizes com tudo alocado
}

void printAllM(Matriz *matriz, int qtdMatrizes){ // Função p/ imprimir todas as matrizes q estão no vetor

    printf("\n---IMPRIMINDO AS MATRIZES---\n\n");
    for (int i = 0; i < qtdMatrizes; i++) { // Percorre o vetor de matrizes
        for (int l = 0; l < matriz[i].qtdLinhas; l++) { // Percorre as matrizes armazenadas
            for (int c = 0; c < matriz[i].qtdColunas; c++) {
                printf("%d ", matriz[i].valor[l][c]); // Imprime os dados de cada matriz do vetor formatados
            }
            printf("\n");
        }
        printf("\n");
    }
}

void mat_q1(int **m, int qtdLinhas, int qtdColunas){ // Função p/ transformar matriz em vetor
    char opc = 'c'; // Forçando a condição de coluna p/ testes

    printf("Você quer transformar linhas ou colunas ( L/C )? ");
    //scanf("%c", &opc);

    printf("\nMatriz tranformada em vetor: \n");

    if (opc == 'L' || opc == 'l'){ // Lógica p/ linhas
        for (int l = 0; l < qtdLinhas; l++) { // Percorre as linhas da matriz
            for (int c = 0; c < qtdColunas; c++) { // Percorre as colunas da matriz
                printf("%d ", m[l][c]);
            }
        }
    }
    
    else if (opc == 'C' || opc == 'c'){ // Lógica p/ colunas 
        for (int c = 0; c < qtdColunas; c++) { // Percorre as colunas da matriz
            for (int l = 0; l < qtdLinhas; l++) { // Percorre as linhas da matriz
                printf("%d ", m[l][c]); // Imprime com a formatação de vetor
            }
        }
    } 
    printf("\n");
}

Matriz mat_q2S(Matriz matriz){ // Função p/ adicionar linhas ou colunas a uma matriz específica
    int qtd; // Quantidade de linhas ou colunas a serem adicionadas
    char opc = 'c'; // Escolha do usuário se será linha ou coluna

    //printf("Você deseja adicionar uma linha ou uma coluna ( L/C )? ");
    //scanf("%d", &opct); 

    printf("Quantas você deseja adicionar? ");
    scanf("%d", &qtd);

    if (opc == 'l'){ // Condicional p/ adicionar linhas
        /* P/ adicionar linhas devemos realocar a matriz adicionando mais vetores e alocar os vetores novos, em termos 
        mais teóricos devemos alocar os ponteiros e depois inteiros  para os quais esse ponteiro irá apontar */
        matriz.valor = (int**)realloc(matriz.valor, (matriz.qtdLinhas + qtd)*sizeof(int*)); //  Realoca a matriz (m**) p/ novo tamanho
        for (int l = matriz.qtdLinhas; l < (matriz.qtdLinhas + qtd); l++) { // Percorre as novas linhas (Vetores) adicionados
            matriz.valor[l] = (int*)calloc(matriz.qtdColunas, sizeof(int)); // Aloca a memoria p/ a nova linha (vetor)
            for (int c = 0; c < matriz.qtdColunas; c++) { // Percorre os novos espaços (Colunas) da nova linha 
                int val;
                printf("Digite o novo valor do elemento [%d][%d]: ", l, c);
                scanf("%d", &val);
                matriz.valor[l][c] = val; // Faz o preenchimento da nova linha
            }
        }
        matriz.qtdLinhas += qtd; // Faz o incremento p/ a nova quantidade de linhas
    }
    else if (opc == 'c'){ // Condicional p/ adicionar colunas
    /* P/ adicionar colunas devemos realocar cada linha da matriz p/ um novo tamanho somado ao tamanho antigo, em termos
    mais teóricos devemos realocar os ponteiros p/ apontarem p/ mais inteiros */
        for (int l = 0; l < matriz.qtdLinhas; l++){ // Percorre as linhas da matriz
            matriz.valor[l] = (int*)realloc(matriz.valor[l], (matriz.qtdColunas + qtd)*sizeof(int)); // Aloca memoria p/novas colunas (realoca os vetores da matriz(linhas))
            for (int c = matriz.qtdColunas; c < (matriz.qtdColunas + qtd); c++) { // Percorre somente as novas colunas da linha
                int val;
                printf("Digite o novo valor do elemento [%d][%d]: ", l, c);
                scanf("%d", &val);
                matriz.valor[l][c] = val; // Faz o preenchimento da nova coluna
            }
        }
        matriz.qtdColunas += qtd; // Faz o incremento p/ a nova quantidade de colunas
    }
    return matriz; // Retorna a matriz (Struct) realocada com a novas linhas ou colunas
}

Matriz mat_q3S(Matriz matriz){
    int qtd;
    char opc = 'c';

    //printf("Você deseja Remover uma linha ou uma coluna ( L/C )? ");
    //scanf("%d", &opct);

    printf("Quantas você deseja Remover? ");
    scanf("%d", &qtd);

    if (opc == 'l'){// Condicional remover linha
        /* P/ remover uma linha devemos primeiro liberar a memória alocada p/ linha (ponteiro) dps realocar a matriz
        p/ a nova quantidade de linhas */
        for (int l = matriz.qtdLinhas - qtd; l < matriz.qtdLinhas; l++) { // Percorre as linhas da matriz
            free(matriz.valor[l]); // Libera a memória alocada p linha (ponteiro)
        }
        matriz.valor = (int**)realloc(matriz.valor, (matriz.qtdLinhas - qtd)*sizeof(int*)); // Realoca a matriz
        matriz.qtdLinhas -= qtd; // Faz o incremento p/ a nova quantidade de linhas
    }

    else if (opc == 'c'){ // Condicional remover coluna
        /* P/ remover uma coluna devemos realocar cada linha (ponteiro) p/ o novo tamanho desejado */
        for (int l = 0; l < matriz.qtdLinhas; l++) { // Percorre as linhas da matriz
            for (int c = (matriz.qtdColunas - qtd); c < matriz.qtdColunas; c++) { // Percorre as colunas da matriz
                matriz.valor[l] = (int*)realloc(matriz.valor[l], sizeof(int)); // Realoca cada linha (ponteiro) p/ o novo tamanho
            }
        }
        matriz.qtdColunas -= qtd; // Faz o incremento p/ a nova quantidade de colunas
    }
    return matriz;
}

void mat_q4(int **m, int qtdLinhas, int qtdColunas){ // passar como parametros o vetorzao e o tamanho dele
    int maior = m[0][0], menor = m[0][0], nPares=0, nImpares=0;
    
    for (int l = 0; l < qtdLinhas; l++) { // Percorre as linhas da matriz
        for(int c=0; c<qtdColunas; c++){ // percorre as colunas da matriz
            if (maior < m[l][c]) // Comparação de um elemento com o próximo p/ saber qual o maior
                maior = m[l][c];
            if (menor > m[l][c]) // comparação de um elemento com o próximo p/ saber qual o menor
                menor = m[l][c];
            if ((m[l][c] % 2) == 0) // verifica se é par ou impar
                nPares++; // caso seja par incrementar o contador de nº pares
            else
                nImpares++; // caso contrario incrementa o contador de nº ímpares
        }
    }
    printf("O maior eh %d e o menor eh %d, tem %d numeros pares e %d impares\n", maior, menor, nPares, nImpares);
}

int main(){
    Matriz *matriz; // Vetor de structs (Vetor de matrizes)
    int qtdMatrizes; // Quantidade de matrizes a serem inseridas

    printf("Quantas matrizes você quer?\n");
    scanf("%d", &qtdMatrizes);

    matriz = alocaAllM(matriz, qtdMatrizes); // Aloca o vetor de matrizes e as matrizes que estão dentro dele
    //lerMatrizes(m, qtdMatrizes);
    printAllM(matriz, qtdMatrizes); // Imprime todas as matrizes inseridas no vetor

    //matriz[0] = mat_q2S(matriz[0]); // Teste de reatribuição de uma matriz (Struct) com novas linhas ou colunas
    matriz[0] = mat_q3S(matriz[0]);
    printAllM(matriz, qtdMatrizes); // Imprime todas as matrizes inseridas no vetor
    //printf("Qntd de novas linhas: %d \n", matriz[0].qtdLinhas);
    printf("Qntd de novas colunas: %d\n", matriz[0].qtdColunas);
        
    return 0;
}






