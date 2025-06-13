#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"

struct list{
    Student *firstStudent;
    Student *lastStudent;
    int size;
};

struct student{
    Student *nextStudent;
    Student *prvStudent;
    char *name;
    int e_number;
      
};

List *createList(){
    List *list = (List*)malloc(sizeof(List));
    if(list == NULL){
        printf("It was not possible to create the list...\n");
        return NULL;
    }
    list->firstStudent = NULL;
    list->lastStudent = NULL;
    list->size = 0;
    printf("List created!\n");
    return list;
}

void insert_at_start(List *list, char *name, int e_number){
    Student *student = (Student*)malloc(sizeof(Student)); 
    
    if(student == NULL){
        printf("It was not possible to insert the student in the list...");
        return;
    }

    student->name = malloc(strlen(name) + 1);
    strcpy(student->name, name);
    student->e_number = e_number;
    student->nextStudent = list->firstStudent;
    student->prvStudent = NULL;
    
    if(list->firstStudent == NULL){
        list->lastStudent = student;
    }
    else{
        list->firstStudent->prvStudent = student;
    }
    list->firstStudent = student;
    list->size++;

}

void insert_at_end(List *list, char *name, int e_number){
    Student *student = (Student*)malloc(sizeof(Student));
    if(student == NULL){
        printf("It was not possible to insert the student...");
        return;
    }
    student->name = malloc(strlen(name) + 1);
    strcpy(student->name, name);
    student->e_number = e_number;
    student->nextStudent = NULL;

    if(list->lastStudent == NULL){
        list->firstStudent = student;
        list->firstStudent->prvStudent = NULL;
    } 
    else{
        list->lastStudent->nextStudent = student;
        student->prvStudent = list->lastStudent;
    }
    list->lastStudent = student;
    list->size++;
  
}

void print_list(List *list){
    Student *currentStudent = list->firstStudent;
    
    if(list->firstStudent == NULL){
        printf("The list is empty!");
        return;
    }

    for(int i = 1; currentStudent != NULL; i++){
        printf("%d Student: %s, E_Number: %d\n", i, currentStudent->name, currentStudent->e_number);
        currentStudent = currentStudent->nextStudent;
    }

}


