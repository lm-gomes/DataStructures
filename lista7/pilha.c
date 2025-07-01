#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct stack{
    Node *firstNode;
    int tam;
};

struct node{
    char *string;
    Node *nextNode;
    
};

Stack *create_stack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL){
        printf("It was not possible to create the stack...\n'");
        return NULL;
    }
    stack->firstNode = NULL;
    stack->tam = 0;
    printf("Stack created!\n");
    return stack;    
}

void push(Stack *stack, const char *string){
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("It was not possible to push to the stack...\n");
        return;
    }
    node->string = (char*)malloc(sizeof(char) * strlen(string) + 1);
    strcpy(node->string, string);
    node->nextNode = stack->firstNode;
    stack->firstNode = node;
    stack->tam++;
}

void pop(Stack *stack){
    if(stack->firstNode == NULL){
        printf("The stack is empty...\n");
        return;
    }

    Node *currentNode = stack->firstNode;
    stack->firstNode = stack->firstNode->nextNode;
    free(currentNode->string);
    free(currentNode);
    stack->tam--;
}

const char *peek(Stack *stack){
    if(stack->firstNode == NULL){
        return "Empty";
    }

    return stack->firstNode->string;
}

void destroy_stack(Stack *stack){
    Node *currentNode;

    while(stack->firstNode != NULL){
        currentNode = stack->firstNode;
        stack->firstNode = currentNode->nextNode;
        free(currentNode->string);
        free(currentNode);
    }
    free(stack);
    printf("Stack deleted!\n");
    
}

