
/*
 2*2=2+2
 -2*2= -2+(-2)
 2*-2=-2*2
 -2*-2=2*1

 */


int ProdottoNegativiRec(int a, int b, int res) {
	if (b==0)
	{
		return res;
	}
	if (b > 0) {

		return ProdottoNegativiRec(a, --b, res + a);
	}
	else // b negativa
	{
		return ProdottoNegativiRec(-a, -b, res);
	}
}



int ProdottoNegativi(int a, int b) {
	return ProdottoNegativiRec(a, b, 0);
}

//int  main(void) {
//	ProdottoNegativi(2, -3);
//	return 0;
//}