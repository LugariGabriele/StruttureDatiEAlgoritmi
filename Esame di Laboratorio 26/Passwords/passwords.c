#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool PasswordValida(int* str, int n) {

	bool coppia_uguale = false;
	for (int i = 1; i < n; i++)
	{
		if (str[i] < str[i - 1]) // decresce
		{
			return false;
		}

		if (str[i] == str[i - 1])
		{
			coppia_uguale = true;
			break; //mi basta una coppia uguale
		}
	}


	if (coppia_uguale == false)
	{
		return false;
	}

	return true;
}

void PasswordRec(int* pass, int n, int idx, int* nsol) {

	if (idx == n) // password piena
	{
		if (PasswordValida(pass, n)) {

			//stampo password
			printf("%d) ", *nsol);
			(*nsol)++;
			for (int j = 0; j < n; j++)
			{
				printf("%d", pass[j]);
			}

			printf("\n");
		}
		return;
	}

	if (idx > n) // controllo per sicurezza
	{
		return;
	}


	for (int num = 0; num < 10; num++)
	{
		if (idx == 0 || num >= pass[idx - 1]) { // non decrecente
			pass[idx] = num;
			PasswordRec(pass, n, idx + 1, nsol);
		}
	}

}

void Passwords(int n) {

	if (n < 2)
	{
		return;
	}

	int* pass = malloc(n * sizeof(int));

	int nsol = 1;
	PasswordRec(pass, n, 0, &nsol);
	free(pass);

}


//int main(void) {
//
//	int n = 3;
//	Passwords(n);
//}