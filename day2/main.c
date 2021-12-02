#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum DIRECTION{
	D_FWD, D_UP, D_DWN
} DIRECTION;

DIRECTION parse_dir(char *stri){
	char *options[] = {"forward", "up", "down"};
	for (DIRECTION i = D_FWD; i <= D_DWN; i++){
		if (strcmp(stri, options[i]) == 0){return i;}
	}
	return -1;
}

int main(){

/* Task 1 */
/*
	char dir[10];
	int val;

	int hor = 0, depth = 0;

	while (scanf("%s %d", dir, &val) != -1){
		DIRECTION dir_enum = parse_dir(dir);
		switch (dir_enum){
			case D_FWD:
				hor += val;
				break;
			case D_UP:
				depth -= val;
				break;
			case D_DWN:
				depth += val;
				break;
		}
	}
	printf(("hor: %d, depth: %d\n"), hor, depth);
	printf(("final: %d\n"), hor * depth);
// */

/* Task 2 */

	char dir[10];
	int aim = 0;
	int val;

	int hor = 0, depth = 0;

	while (scanf("%s %d", dir, &val) != -1){
		DIRECTION dir_enum = parse_dir(dir);
		switch (dir_enum){
			case D_FWD:
				hor += val;
				depth += aim * val;
				break;
			case D_UP:
				aim -= val;
				break;
			case D_DWN:
				aim += val;
				break;
		}
	}
	printf(("final: %d\n"), hor * depth);

	return 1;
}
