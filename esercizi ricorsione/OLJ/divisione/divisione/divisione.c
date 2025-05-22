
/*
4/2= 2 volte 4-2=0
5/2=2.5 ==2 

*/



int DivisioneRec(int a, int b, int res) {
	if (a - b<0)
	{
		return res;
	}
	return DivisioneRec(a - b, b, ++res);

}




int Divisione(int a, int b) {
	if (a<0||b<=0)// se negativi o impossibile
	{
		return -1;
	}
	return DivisioneRec(a, b, 0);
}


//int main(void) {
//	Divisione(7, 2);
//	return 0;
//
