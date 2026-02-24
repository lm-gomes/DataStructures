#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(array[j] > array[j + 1]){
				int aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}
		}
	}
}

void print_array(int *array, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	int array[5] = {5, 2, 9, 3, 1};
	print_array(array, 5);
	bubble_sort(array, 5);
	print_array(array, 5);
	
	return 0;
}