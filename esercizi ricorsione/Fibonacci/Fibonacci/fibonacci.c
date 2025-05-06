/*
n:		0	1	2	3	4	5
F(n)	0	1	1	2	3	5

*/





int FibonacciRec(int n,int a,int b ) {
	//a= Fn-2
	//b= Fn-1
	if (n == 0) return a; // casi base
	if (n == 1) return b; // caso uscita e base stesso

	return FibonacciRec(n - 1, b, a + b);
}


int Fibonacci(int n) {
	if (n<0)
	{
		return-1;
	}
	return FibonacciRec(n, 0, 1);
}


int main(void) {
	Fibonacci(6);
	return 0;
}