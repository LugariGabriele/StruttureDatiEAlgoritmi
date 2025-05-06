
/*

123-> 123/10=12-> 0+3
12-> 12/10=1 -> 30+2

*/




int InvertiCifreRec(int n,int res) {
	if (n==0)
	{
		return res;
	}

	return InvertiCifreRec(n / 10, res * 10 + n % 10);

}


int InvertiCifre(int n) {

	if (n<0)
	{
		return -InvertiCifreRec(-n,0);
	}
	return InvertiCifreRec(n,0);
}

int main(void) {
	InvertiCifre(543);
	return 0;
}