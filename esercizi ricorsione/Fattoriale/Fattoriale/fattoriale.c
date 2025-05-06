
unsigned long long FattorialeRec(int n,unsigned long long res) {
	if (n==0||n==1)
	{
		return res;
	}

	return FattorialeRec(n - 1, res * n);
}





unsigned long long Fattoriale(int n) {
	if (n < 0)
	{
		return 0;
	}
	return FattorialeRec(n, 1);
}

