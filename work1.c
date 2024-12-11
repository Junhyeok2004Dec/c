#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
		
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);

	if (x >= y) {
		if (z >= x) {
			printf("%d (ÀÌ)°¡ °¡Àå Å®´Ï´Ù ", z);
		}
		else {
			printf("%d (ÀÌ)°¡ °¡Àå Å®´Ï´Ù ", x);
		}
	}
	else {
		if (z >= y) {
			printf("%d (ÀÌ)°¡ °¡Àå Å®´Ï´Ù ", z);

		}
		else {
			printf("%d °¡ °¡Àå Å®´Ï´Ù ", y);

		}
	}


}