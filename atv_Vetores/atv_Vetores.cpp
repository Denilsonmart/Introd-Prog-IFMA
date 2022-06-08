#include <stdio.h>
#include <stdlib.h>

void printM(int **m, int tamM, int *tamVets){
    
    for(int i=0; i<tamM; i++){
      for(int j=0; j<tamVets[tamM-1]; j++)
        printf("%d", m[i][j]);
    printf("\n");
    }
}   

void adcVet(int **m, int *tamVets, int tamM){
  int *vet, tamVetor, valor;

  printf("Digite o tamanho do vetor q c quer: ");
  scanf("%d", &tamVetor);

  tamVets[tamM] = tamVetor;

  vet = (int*)calloc(tamVetor, sizeof(int));

  for(int i=0; i<tamVetor; i++){
    printf("Valor p/ o elemento [%d]: ", i);
    scanf("%d", &valor);
     vet[i] = valor;
  }

  m[tamM] = vet;
}

int main(){

  int **m,*tamVets, tamM=0;

  //printf("Digita um valor a vacilao:\n");

  m = (int**)calloc(1, sizeof(int*));
  tamVets = (int*)calloc(1, sizeof(int));
  
  adcVet(m, tamVets, tamM);
  tamM++;
  printM(m, tamM,tamVets);
  //printf("%d\n", tamM);

  return 0; 
}
