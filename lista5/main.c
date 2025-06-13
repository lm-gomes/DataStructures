#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(){
    
    List *list = createList();
    char *name = "Lucas";
    insert_at_start(list, name, 566123);
    insert_at_start(list, "Guilherme", 566150);
    insert_at_end(list, "Luzia", 566151);
    print_list(list); 

    return 0;
}
