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
        printf("\n---PREENCHER MATRIZ %d---\n\n", i+1);
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
        printf("\nMatriz %d:\n", i+1);
        printf("Quantas linhas? ");
        scanf("%d", &(matriz[i].qtdLinhas)); // Faz a atribuição das linhas de cada matriz no vetor
        printf("Quantas colunas? ");
        scanf("%d", &(matriz[i].qtdColunas)); // Faz a atribuição das coluans de cada matriz no vetor

        matriz[i].valor = (int**)calloc(matriz[i].qtdLinhas, sizeof(int*)); // Aloca as matrizes que estão dentro do vetor
        for (int l = 0; l < matriz[i].qtdLinhas; l++) { // Percorre as linhas das matrizes armazenadas dentro do vetor
            matriz[i].valor[l] = (int*)calloc(matriz[i].qtdColunas, sizeof(int)); // Aloca as linhas (vetores) das matrizes armazenadas
        }
    }
    return matriz; // Retorna o vetor de matrizes com tudo alocado
}

void printAllM(Matriz *matriz, int qtdMatrizes){ // Função p/ imprimir todas as matrizes q estão no vetor

    for (int i = 0; i < qtdMatrizes; i++) { // Percorre o vetor de matrizes
        printf("Matriz %d:\n\n", i+1);
        for (int l = 0; l < matriz[i].qtdLinhas; l++) { // Percorre as matrizes armazenadas
            printf("| ");
            for (int c = 0; c < matriz[i].qtdColunas; c++) {
                printf("%d ", matriz[i].valor[l][c]); // Imprime os dados de cada matriz do vetor formatados
            }
            printf("|\n");
        }
        printf("\n");
    }
}

void mat_q1(Matriz matriz){ // Função p/ transformar matriz em vetor
    char opc; // Forçando a condição de coluna p/ testes

    printf("\nVocê quer transformar linhas ou colunas ( L/C )? ");
    scanf("%c", &opc);
    scanf("%c", &opc);

    printf("\nMatriz tranformada em vetor: \n");

    if (opc == 'L' || opc == 'l'){ // Lógica p/ linhas
        for (int l = 0; l < matriz.qtdLinhas; l++) { // Percorre as linhas da matriz
            for (int c = 0; c < matriz.qtdColunas; c++) { // Percorre as colunas da matriz
                printf("%d ", matriz.valor[l][c]);
            }
        }
    }
    
    else if (opc == 'C' || opc == 'c'){ // Lógica p/ colunas 
        for (int c = 0; c < matriz.qtdColunas; c++) { // Percorre as colunas da matriz
            for (int l = 0; l < matriz.qtdLinhas; l++) { // Percorre as linhas da matriz
                printf("%d ", matriz.valor[l][c]); // Imprime com a formatação de vetor
            }
        }
    } 
    printf("\n");
}

Matriz mat_q2S(Matriz matriz){ // Função p/ adicionar linhas ou colunas a uma matriz específica
    int qtd; // Quantidade de linhas ou colunas a serem adicionadas
    char opc; // Escolha do usuário se será linha ou coluna

    printf("Você deseja adicionar uma linha ou uma coluna ( L/C )? ");
    scanf("%c", &opc);
    scanf("%c", &opc); // utilizado p/ limpar o buffer do teclado devido a tecla enter

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
    char opc;

    printf("Você deseja Remover uma linha ou uma coluna ( L/C )? ");
    scanf("%c", &opc);
    scanf("%c", &opc); // Utilizado p/ limpar o buffe do teclado devido a tecla enter

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

void mat_q4(Matriz matriz){ // passar como parametros o vetorzao e o tamanho dele
    int maior = matriz.valor[0][0], menor = matriz.valor[0][0], nPares=0, nImpares=0;
    
    for (int l = 0; l < matriz.qtdLinhas; l++) { // Percorre as linhas da matriz
        for(int c = 0; c < matriz.qtdColunas; c++){ // percorre as colunas da matriz
            if (maior < matriz.valor[l][c]) // Comparação de um elemento com o próximo p/ saber qual o maior
                maior = matriz.valor[l][c];
            if (menor > matriz.valor[l][c]) // comparação de um elemento com o próximo p/ saber qual o menor
                menor = matriz.valor[l][c];
            if ((matriz.valor[l][c] % 2) == 0) // verifica se é par ou impar
                nPares++; // caso seja par incrementar o contador de nº pares
            else
                nImpares++; // caso contrario incrementa o contador de nº ímpares
        }
    }
    printf("\n\nO maior é %d e o menor é %d, tem %d numeros pares e %d impares\n\n", maior, menor, nPares, nImpares);
}

void menu(){
    printf("\n-------------------- MENU ---------------------\n");
    printf("\n 1 - Imprimir matrizes armazenadas: \n");
    printf("\n 2 - Transformação da matriz em vetor (linha ou coluna):\n");
    printf("\n 3 - Adicionar novos elementos a uma matriz:\n");
    printf("\n 4 - remover elementos de uma matriz:\n");
    printf("\n 5 - Fornecer o maior, menor, quantidade de números ímpares e pares: \n");
    printf("\n 6 - Encerrar programa: \n");
}

void delay(){
    printf("pressione enter p/ continuar...");
    getchar();
    getchar();
    system("clear");
}

int main(){
    Matriz *matriz; // Vetor de structs (Vetor de matrizes)
    int qtdMatrizes, opc, nMatriz; // Quantidade de matrizes a serem inseridas

    printf("\nQuantas matrizes você quer?\n");
    scanf("%d", &qtdMatrizes);

    matriz = alocaAllM(matriz, qtdMatrizes); // Aloca o vetor de matrizes e as matrizes que estão dentro dele
    lerMatrizes(matriz, qtdMatrizes); // Função p/ q o usuário entre com os valores da matriz

    while (opc != 6) {

        menu();
        printf("\nQue operação você deseja realizar? ");
        scanf("%d", &opc);
        printf("-----------------------------------------------\n");
        system("clear");

        switch (opc) {
            case 1: 
            
                printAllM(matriz, qtdMatrizes);
                delay();
                break;

            case 2:

                printAllM(matriz, qtdMatrizes);
                printf("\nEm qual matriz vocẽ deseja transformar em vetor? ");
                scanf("%d", &nMatriz);
                mat_q1(matriz[nMatriz-1]);
                delay();
                break;

            case 3:

                printAllM(matriz, qtdMatrizes);
                printf("\nEm qual matriz vocẽ deseja adicionar novos elementos? ");
                scanf("%d", &nMatriz);
                matriz[nMatriz-1] = mat_q2S(matriz[nMatriz-1]);
                delay();
                break;

            case 4: 

                printAllM(matriz, qtdMatrizes);
                printf("\nEm qual matriz vocẽ deseja remover elementos? ");
                scanf("%d", &nMatriz);

                matriz[nMatriz-1] = mat_q3S(matriz[nMatriz-1]);
                delay();
                break;

            case 5:

                printAllM(matriz, qtdMatrizes);
                printf("\nEm qual matriz vocẽ deseja fazer essa operação? ");
                scanf("%d", &nMatriz);
                mat_q4(matriz[nMatriz-1]);
                delay();
                break;

            case 6: break;

            default: printf("opção inválida!");
        }
    }
        
    return 0;
}





