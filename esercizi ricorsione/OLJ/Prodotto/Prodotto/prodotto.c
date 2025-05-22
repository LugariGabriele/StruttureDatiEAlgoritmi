
/*
* 
* 2*3 = 2+2+2
* 5*4= 5+5+5+5
* 
*/




int ProdottoRec(int a, int b, int res) {
	if (b==0)
	{
		return res;
	}
	res += a;
	return ProdottoRec(a, --b, res);
}


int Prodotto(int a, int b) {
	if (a<0||b<0)
	{
		return -1;
	}
	return ProdottoRec(a, b, 0);

}
//
//int main(void) {
//	Prodotto(5, 3);
//	return 0;
//}