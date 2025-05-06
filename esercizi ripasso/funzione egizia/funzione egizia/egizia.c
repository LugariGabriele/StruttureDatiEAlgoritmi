#include <stdio.h>
#include <math.h>


void FrazioneEgiziaRec(int n, int d) {
	
	
	int x = (int)ceil((double)d / n);

	printf("1/%d", x);
	

	//
	int new_n = n * x - d;
	int new_d = d * x;

	if (d % n == 0)
	{
		return;
	}
	else
	{
		printf(" + ");

	}

	return FrazioneEgiziaRec(new_n, new_d);

}



void FrazioneEgizia(int n, int d) {
	if (n<=0 || d<=0|| n>d)
	{
		printf("Impossibile convertire la frazione");
	}
	return FrazioneEgiziaRec(n, d);
}
int main(void) {

	FrazioneEgizia(7, 24);
	return 0;
}