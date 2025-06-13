#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"

struct student{
    char *name;
    int e_number;
      
};

struct list{
    Node *firstNode;
    Node *lastNode;
    int size;
};

struct node{
    Node *nextNode;
    Student student;
    Node *prvNode;
};


List *createList(){
    List *list = (List*)malloc(sizeof(List));
    if(list == NULL){
        printf("It was not possible to create the list...\n");
        return NULL;
    }
    list->firstNode = NULL;
    list->lastNode = NULL;
    list->size = 0;
    printf("List created!\n");
    return list;
}

void insert_at_start(List *list, char *name, int e_number){

    Node *node = (Node*)malloc(sizeof(Node)); 
    
    if(node == NULL){
        printf("It was not possible to insert the student in the list...");
        return;
    }
    node->student.name = malloc(sizeof(strlen(name) + 1));
    
    strcpy(node->student.name, name);
    node->student.e_number = e_number;
    node->nextNode = list->firstNode;
    node->prvNode = NULL;
    
    if(list->firstNode == NULL){
        list->lastNode = node;
    }
    else{
        list->firstNode->prvNode = node;
    }
    list->firstNode = node;
    list->size++;

}

void insert_at_end(List *list, char *name, int e_number){
    Node *node = (Node*)malloc(sizeof(Node));

    if(node == NULL){
        printf("It was not possible to insert the student...");
        return;
    }
    node->student.name = malloc(strlen(name) + 1);
    strcpy(node->student.name, name);
    node->student.e_number = e_number;
    node->nextNode = NULL;

    if(list->lastNode == NULL){
        list->firstNode = node;
        list->firstNode->prvNode = NULL;
    } 
    else{
        list->lastNode->nextNode = node;
        node->prvNode = list->lastNode;
    }
    list->lastNode = node;
    list->size++;
  
}

void insert_after_enumber(List *list, char *name, int e_number){
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("It was not possible to insert into the list...");
        return;
    }
    node->student.name = malloc(strlen(name) + 1);
    strcpy(node->student.name, name);
    node->student.e_number = e_number;
    
    Node *currentNode = list->firstNode;   

    while(currentNode != NULL && currentNode->student.e_number != e_number){
        currentNode = currentNode->nextNode;
    }

    if(currentNode == NULL){
        printf("The value was not found in the list...");
        return;
    }

    node->nextNode = currentNode->nextNode;
    currentNode->nextNode->prvNode = node;
    node->prvNode = currentNode;
    currentNode->nextNode = node;
    
        
}

void print_list(List *list){
    Node *currentNode = list->firstNode;
    
    if(list->firstNode == NULL){
        printf("The list is empty!");
        return;
    }

    for(int i = 1; currentNode != NULL; i++){
        printf("%d Student: %s, E_Number: %d\n", i, currentNode->student.name, currentNode->student.e_number);
        currentNode = currentNode->nextNode;;
    }

}


