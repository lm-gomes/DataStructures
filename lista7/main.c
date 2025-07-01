#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    
    Stack *myStack = create_stack();
    push(myStack, "Lucas");
    printf("Top > %s\n", peek(myStack)); 
    pop(myStack);
    printf("Top > %s\n", peek(myStack));
    destroy_stack(myStack);
    push(myStack, "Algo");
    
    return 0;
}
