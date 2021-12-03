#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define NUMLEN 12

int eval_bin(int *msb, int length){

	int total = msb[0];
	
	for (int i = 1; i < length; i++){
	
		total = (2 * total) + msb[i]; 

	}

	return total;
}

void get_msb(int *msb, int *sum, int len, int num_count){

	int halfpoint = num_count / 2;

	for (int i = 0; i < len; i++){
	
		if (sum[i] > halfpoint){msb[i] = 1;}
		else {msb[i] = 0;}

	}
}

int get_compliment(int sum, int num_count){
	return (int)(pow(2, num_count) - sum) - 1;
}

void print_bin(int *msb, int length){

	for (int i = 0; i < length; i++){
	
		printf("%d", msb[i]); 

	}
	printf("\n");
}

int main(){

	int *weird_sum = calloc(NUMLEN, sizeof(int));

	int c;

	int count = 0, pos = 0;


	while ((c = getchar())!= EOF){
		switch (c){
			case (int)'\r':
				c = getchar(); //fallthrough
			case (int)'\n':
				count++;
				break;

			case (int)'1':
				weird_sum[pos] += 1; //fallthrough

			case (int)'0':
				pos++;
				break;
		}
		if (pos >= NUMLEN){pos = 0;}
	}

	int *msb = calloc(NUMLEN, sizeof(bool));
	get_msb(msb, weird_sum, NUMLEN, count);

	int sum = eval_bin(msb, NUMLEN);
	int com = get_compliment(sum, NUMLEN);

	print_bin(msb, NUMLEN);
	printf("Gamma   MSB sum %d\n", sum);
	printf("Epsilon LSB com %d\n", com);
	printf("Power consumpt  %d\n", sum * com);



	return 1;
}
