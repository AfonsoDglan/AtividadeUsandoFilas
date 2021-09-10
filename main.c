#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
struct PixED{
  int id_orig;
  int id_dest;
  float valor;
};
int main(){
  int vezes;
  int conta_origem,conta_destino;
  float valor;
  pixEd pixed;
  pixEd temp;
  Queue* filadepix = Queue_create();
  printf("Digite o total de pix que deseja fazer: ");
  scanf("%d",&vezes);
  while(1){
    if(Queue_qty(filadepix) == vezes){
      for(int i = 0;i < vezes;i++){
        Queue_dequeue(filadepix,&temp);
        printf("(%d, %d, %.2f),",temp.id_orig,temp.id_dest,temp.valor);
      }printf("\n");
    }else{
      printf("Conta Origem: ");
      scanf("%d",&conta_origem);
      printf("Conta Destino: ");
      scanf("%d",&conta_destino);
      printf("Valor: ");
      scanf("%f",&valor);
      if(conta_origem == 0 && conta_destino == 0){
        if(Queue_qty(filadepix) == 0){
          break;
        }else{
          for(int i = 0;i < Queue_qty(filadepix);i++){
            Queue_dequeue(filadepix,&temp);
            printf("(%d, %d, %.2f),",temp.id_orig,temp.id_dest,temp.valor);
          }
          break; 
        }
      }
      pixed.id_orig = conta_origem;
      pixed.id_dest = conta_destino;
      pixed.valor = valor;
      if(!Queue_enqueue(filadepix,pixed)){
        printf("Nao pude inserir\n");
      }
    }
  }
  return 0;
}