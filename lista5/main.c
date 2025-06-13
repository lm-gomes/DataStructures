#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(){
    
    List *list = createList();
    char *name = "Lucas";
    insert_at_start(list, name, 566123);
    insert_at_start(list, "Rita", 123456);
    insert_at_start(list, "Obede", 765432);
    insert_at_start(list, "Kat", 156942);
    insert_at_end(list, "AbacateComFeijao", 999999);
    print_list(list);

    
    return 0;
}
