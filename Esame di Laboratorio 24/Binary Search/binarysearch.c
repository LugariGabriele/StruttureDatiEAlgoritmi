#include <stdlib.h>

int BinarySearch(const int* v, size_t v_size, int value) {


	int mid, middle;
	int first = 0;
	int last = v_size - 1;
	while (first <= last) {

		mid = (first + last) / 2;
		middle = v[mid];
		if (middle == value)
		{
			return mid;
		}
		else if (middle < value) { //cerco a dx
			first = mid + 1;
		}
		else //cerco a sx
		{
			last = mid - 1;
		}
	}

	return -1;
}

//
//int main(void) {
//	int v[] = { 2,3,4,6 };
//	size_t size = sizeof(v) / sizeof(v[0]);
//	int res =BinarySearch(v, size, 6);
//
//}