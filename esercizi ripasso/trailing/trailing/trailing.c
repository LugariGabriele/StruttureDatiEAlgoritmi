


unsigned int TrailingZerosRec(unsigned int n,unsigned int res) {
	if (n==0)
	{
		return res;
	}
	return TrailingZerosRec(n / 2, res + (n / 2));
}



unsigned int TrailingZeros(unsigned int n) {
	return TrailingZerosRec(n, 0);
}
int main(void) {
	TrailingZeros(12);
	return 0;
}