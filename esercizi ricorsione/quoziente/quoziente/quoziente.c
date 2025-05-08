#include <stdlib.h>

int QuozienteRec(size_t x, size_t y, int count) {
	if (x<y)
	{
		return count;
	}

	return QuozienteRec(x - y, y, count++);

}

int Quoziente(size_t x, size_t y) {
	if (y==0)
	{
		return -1;
	}
	return QuozienteRec(x, y, 0);
}

int main(void) {
	Quoziente(8, 3);
	return 0;
}