#include <stdlib.h>

void InvertiArrayRec(int* arr, size_t size, size_t i) {
	if (i==size/2)
	{
		return;
	}
	
	int tmp = arr[i];
	arr[i] = arr[size - 1-i];
	arr[size - 1-i] = tmp;
	return InvertiArrayRec(arr, size, ++i);
}


void InvertiArray(int* arr, size_t size) {
	
	if (size==0)
	{
		return;
	}
	return InvertiArrayRec(arr, size, 0);
}

int main(void) {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	InvertiArray(arr, sizeof(arr) / sizeof(int));
	return 0;
}