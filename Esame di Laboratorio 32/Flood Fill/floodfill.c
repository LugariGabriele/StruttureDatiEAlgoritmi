#include "floodfill.h"
#include <stdio.h>

void FloodFill(struct Matrix* img, int x, int y, char old_color,
	char new_color) {

	//controllo se sono oltre i bordi
	if (x < 0 || y < 0 || x >= (int) img->cols || y >= (int)img->rows) {
		return;
	}

	//calcolo pixel in array e creo puntatore per cambiarlo
	char* pixel = &img->data[y * (int)img->cols + x];

	//se colore non è quello da sostituire o se è già quello nuovo non faccio nulla
	if (*pixel != old_color || *pixel == new_color)
	{
		return;
	}

	*pixel = new_color;

	FloodFill(img, x - 1, y, old_color, new_color);// ovest
	FloodFill(img, x + 1, y, old_color, new_color); // est
	FloodFill(img, x, y - 1, old_color, new_color); // nord
	FloodFill(img, x, y + 1, old_color, new_color); // sud

}
//
//void printMatrix(struct Matrix* img) {
//	for (size_t i = 0; i < img->rows; ++i) {
//		for (size_t j = 0; j < img->cols; ++j) {
//			printf("%2d ", img->data[i * img->cols + j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//
//int main(void) {
//    // Dati dell'immagine di esempio
//    char data[] = {
//        1, 1, 3, 4,
//        4, 1, 3, 4,
//        3, 1, 3, 3,
//        3, 1, 3, 3,
//        4, 1, 1, 1
//    };
//
//    struct Matrix img = {
//        .rows = 5,
//        .cols = 4,
//        .data = data
//    };
//
//    printf("Immagine iniziale:\n");
//    printMatrix(&img);
//
//    printf("FloodFill(&img, 0, 0, 1, 5):\n");
//    FloodFill(&img, 0, 0, 1, 5);
//    printMatrix(&img);
//
//    printf("FloodFill(&img, 2, 0, 3, 9):\n");
//    FloodFill(&img, 2, 0, 3, 9);
//    printMatrix(&img);
//
//    printf("FloodFill(&img, 3, 4, 7, 2): (nessun cambiamento atteso)\n");
//    FloodFill(&img, 3, 4, 7, 2);
//    printMatrix(&img);
//
//    return 0;
//}