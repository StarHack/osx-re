#include <stdlib.h>
#include <stdio.h>
#include <time.h>   

char* alphabet = "3489ACGHJKNPTWXZ";
int uniqueness = 0x00;

char nextChar() {
	int num = (uniqueness * 0x343fd) + 0x269ec3;
	uniqueness = num;
	return alphabet[((num >> 0x10) & 0x7fff) % 16];
}

int main(int argc, char* argv[]) {
	char serial[25];

	srand(clock());
	uniqueness = rand() % 0x5049EE;
	
	for(int i=0; i<20; i++) {
		if((i+1) % 5 == 0) {
			serial[i] = '-';
		}
		else{
			serial[i] = nextChar();
		}
	}

	serial[20] = 0x00;

	unsigned int num = 0;
	for(int i=0; i<= 0x12; i++) {
		if(serial[i] == '-') {
			continue;
		}

		num ^= serial[i];

		int j = 8;
		int tmp = j;

		do {
			if((num & 1) != 0) {
				num ^= 0x14002;
			}
			num = num >> 1;
			tmp = j;
			j--;
		} while(tmp != 1);
	}
	
	printf("Empires: Dawn of the Modern World Keygen\n");
	printf("------------------------\n");
	printf("%s", serial);
	printf("%04X\n", num);
	printf("------------------------\n");

	return 0;
}
