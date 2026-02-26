#include <stdio.h>
#include <stdlib.h>

void cocktail_sort(int *array, int n){
		for(int i = 0; i < (n + 1)/2; i++){
			for(int j = i; j < n - i - 1; j++){
				if(array[j] > array[j + 1]){
					int aux = array[j];
					array[j] = array[j + 1];
					array[j + 1] = aux;
				}
			}
			for(int j = n - i - 2; j > i; j--){
				if(array[j] < array[j - 1]){
					int aux = array[j];
					array[j] = array[j - 1];
					array[j - 1] = aux;
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
	int myArray[5] = {5, 2, 9, 3, 1};
	print_array(myArray, 5);
	cocktail_sort(myArray, 5);
	print_array(myArray, 5);
}
