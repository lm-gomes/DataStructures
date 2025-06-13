#ifndef STUDENT_H
#define STUDENT_H

typedef struct list List;
typedef struct student Student;
typedef struct node Node;

List *createList();
void insert_at_start(List *list, char *name, int e_number);
void insert_at_end(List *list, char *name, int e_number);
void print_list(List *list);


#endif
