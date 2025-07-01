#ifndef PILHA_H
#define PILHA_H

typedef struct stack Stack;
typedef struct node Node;

Stack *create_stack();
void push(Stack *stack, const char *string);
void pop(Stack *stack);
const char *peek(Stack *stack);
void destroy_stack(Stack *stack);




#endif
