#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *prv;
	struct node *next;
	int key;

}Node;

typedef struct list{
	Node *firstNode;
	Node *lastNode;
	int size;

}List;

List *create_list(){
	List *list = (List*)malloc(sizeof(List));
	list->firstNode = NULL;
	list->lastNode = NULL;
	list->size = 0;
	printf("oi\n");
	return list;
}

void insert_start(int value, List *list){
	Node *node = (Node*)malloc(sizeof(Node));
	if(node != NULL){
		node->key = value;
		node->next = list->firstNode;
		node->prv = NULL;

		if(list->firstNode != NULL){
			list->firstNode->prv = node;
		}
		list->firstNode = node;
		list->size++;
	}
	printf("Value inserted successfully!\n");
}

void print_list(List *list){
	Node *node = list->firstNode;
	if(node == NULL){
		printf("Empty list!\n");
	}

	while(node != NULL){
		printf("%d ", node->key);
		node = node->next;
	}
	
}

int main(){
	printf("oi\n");
	List *myList = create_list();
	insert_start(2, myList);
	insert_start(5, myList);
	insert_start(4, myList);
	insert_start(8, myList);
	print_list(myList);


}