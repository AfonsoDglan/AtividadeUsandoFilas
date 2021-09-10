#include "Queue.h"
#include <stdlib.h>

struct PixED{
  int id_orig;
  int id_dest;
  float valor;
};

typedef struct no{
  pixEd pix;
  struct no* prox;
}TNo;

TNo* TNo_createNFill(pixEd V){
  TNo* novo = malloc(sizeof(TNo));
  if(novo){
    novo->pix = V;
    novo->prox = novo;
  }return novo;
}

struct queue{
  TNo* end;
  int qty;
};

Queue* Queue_create(){
  Queue* nova = malloc(sizeof(Queue));
  if(nova){
    nova->end = NULL;
    nova->qty = 0;
  }
  return nova;
}
void Queue_destroy(Queue*);

int Queue_enqueue(Queue* fila, pixEd V){
  TNo* novo = TNo_createNFill(V);
  if(!novo) return 0;
  if(fila->end == NULL)
    fila->end = novo;
  else{
      novo->prox = fila->end->prox;
      fila->end->prox = novo;
      fila->end = novo;
  } 
  fila->qty++;
  return 1;
}
int Queue_dequeue(Queue* fila, pixEd* info){
  if(Queue_empty(fila)) return 0;
  TNo* oldBegin = fila->end->prox;
  *info = oldBegin->pix;
  fila->end->prox = oldBegin->prox;
  free(oldBegin);
  fila->qty--;
  if(fila->qty==0)
    fila->end = NULL;
  return 1;
}

int Queue_head(Queue* fila, pixEd* info){
  if(Queue_empty(fila)) return 0;
  TNo* oldBegin = fila->end->prox;
  *info = oldBegin->pix;
  return 1;
}

int Queue_full(Queue* fila){
  return 0;
}
int Queue_empty(Queue* fila){
  return fila->end == NULL;
}
int Queue_qty(Queue* fila){
  return fila->qty;
};
pixEd* dado(){	
	pixEd *dados;
	dados = (pixEd*)malloc(sizeof(pixEd));
	return dados;	
}