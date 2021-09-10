#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;
typedef struct PixED pixEd;

Queue* Queue_create();
void Queue_destroy(Queue*);
int Queue_enqueue(Queue*, pixEd);
int Queue_dequeue(Queue*, pixEd*);
int Queue_head(Queue*, pixEd*);
pixEd* dado();
int Queue_full(Queue*);
int Queue_empty(Queue*);
int Queue_qty(Queue*);

#endif