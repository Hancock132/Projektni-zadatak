#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
	int uvjet = 1;
	printf("***SKLADISTE ALKOHOLNIH PICA***\n\n");

	while (uvjet != 99)
		uvjet = izbornik();

	return 0;
}
