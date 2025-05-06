#include <stdio.h>

size_t HailStoneRec(int n,size_t size) {
	if (n==1)
	{
		printf("%d", n);
		return size;
	}




	printf("%d, ", n);
	if (n%2==0)
	{
		return HailStoneRec(n / 2, ++size);
	}
	return HailStoneRec(3 * n + 1, ++size);

}

size_t Hailstone(int n) {
	if (n<=0)
	{
		return 0;
	}
	return HailStoneRec(n,1);
}

int main(void) {
	Hailstone(5);
	return 0;
}

