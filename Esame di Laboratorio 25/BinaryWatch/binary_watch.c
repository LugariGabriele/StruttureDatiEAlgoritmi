#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int ConvertiLed(bool* v, int v_size) {

	int res = 0;
	for (size_t i = 0; i < v_size; i++)
	{
		if (v[i]) { // led acceso
			double pos = v_size - i - 1;
			res += pow(2.0, pos);
		}
	}
	return res;
}

void ValidTimesRec(uint8_t n, bool* vcurr_min, bool* vcurr_ore, int led_onCurr, int idx) {


	if (led_onCurr > n)
	{
		return;
	}

	if (idx == 11) // ho fatto tutti array
	{
		if (led_onCurr == n) // ho num giusto led accesi
		{

			int min = ConvertiLed(vcurr_min, 6);
			int ore = ConvertiLed(vcurr_ore, 5);

			if (min < 60 && ore < 24) // orario valido
			{

				printf("%02d:%02d, ", ore, min);
			}
			
		}
		return;
	}

	// Prova a NON accendere il LED corrente
	ValidTimesRec(n, vcurr_min, vcurr_ore, led_onCurr, idx + 1);

	if (idx < 5)
	{
		vcurr_ore[idx] = true;
		ValidTimesRec(n, vcurr_min, vcurr_ore, led_onCurr + 1, idx + 1);
		vcurr_ore[idx] = false;
	}
	else
	{
		vcurr_min[idx-5] = true;
		ValidTimesRec(n, vcurr_min, vcurr_ore, led_onCurr + 1, idx + 1);
		vcurr_min[idx-5] = false;
	}

}

void ValidTimes(uint8_t n) {

	if (n > 11)
	{
		return;
	}

	bool* vcurr_min = calloc(6, sizeof(bool));
	bool* vcurr_ore = calloc(5, sizeof(bool));

	ValidTimesRec(n, vcurr_min, vcurr_ore, 0, 0);

	free(vcurr_min);
	free(vcurr_ore);
}

//
//int main(void) {
//
//	uint8_t n = 9;
//	ValidTimes(n);
//}