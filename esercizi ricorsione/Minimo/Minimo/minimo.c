#include <stdlib.h>
int MinimoRec(const int* v, int v_size, int index, int min) {
	if (index==v_size)
	{
		return min;
	}
	if (v[index]<min)
	{
		int nuovomin = v[index];
		return MinimoRec(v, v_size, ++index, nuovomin);
	}
	return MinimoRec(v, v_size, ++index, min);


}




int Minimo(const int* v, int v_size) {
	return MinimoRec(v, v_size, 1,v[0]);
}

//int main(void) {
//	 const int v[] = {10,2,73,1,0};
//	 int size = sizeof(v) / sizeof(int);
//	 int res = minimo(v, size);
//}

