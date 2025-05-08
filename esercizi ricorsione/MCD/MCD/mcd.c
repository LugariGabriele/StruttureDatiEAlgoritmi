

int MCD(int m, int n) {
	if (n == 0) {
		return m;
	}
	return MCD(n, m % n);
}
int main(void) {
	MCD(10, 45);
	return 0;
}
