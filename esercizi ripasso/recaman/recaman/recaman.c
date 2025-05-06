
/*
n=6
a1=1-> a2=a1/2 ? no -> a2=2*1   a3=a2/3? (2/3) no a3=3*a2=6
a4= a3/4 ? (6/4) no a4=4*a3=4*6=24
a5= a4/5 ? (24/5) no a5=5*24=120
a6 = a6* (120/6) ? si  a6=20 XXXXXX


*/

void RecamanRec(int n,int res) {
	if (n==1)
	{
		return res;
	}
	if (res%n==0)
	{
		return RecamanRec(n - 1, res / n);
	}
	return RecamanRec(n - 1, res * n);
}

void Recaman(int n) {
	if (n<1)
	{
		return -1;
	}
	return RecamanRec(n, 1);
}

int main(void) {
	Recaman(6);
	return 0;
}