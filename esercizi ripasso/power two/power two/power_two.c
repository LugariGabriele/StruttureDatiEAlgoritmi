

unsigned int PowertwoRec(unsigned int n, unsigned int count) {


	if (n % 2 == 0)
	{
		count++;
		return PowertwoRec(n / 2, count);
	}
	return count;
}



unsigned int Powertwo(unsigned int n) {

	return PowertwoRec(n, 0);

}

int main(void) {
	Powertwo(100);
	return 0;
}