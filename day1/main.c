#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_higher(int prev, int cur){

	if (prev < cur){return true;}
	else {return false;}
}

int main(){

/* Task 1 */
/*
	int prev, cur, count, state;
	state = scanf("%d", &prev);
	while (scanf("%d", &cur) != -1){
		count += is_higher(prev, cur);
		prev = cur;
	}
	printf("Depth increased %d times\n", count);
*/

/* Task 2 */
	int values[4] = {0,0,0,0};
	int cur_index = 0;
	int count = 0;
	
	for (; cur_index < 3; cur_index++){
		scanf("%d", &(values[cur_index]));
	}

	int new, old;
	while (scanf("%d", &(values[cur_index])) != -1){
		new = values[cur_index];
		old = values[(cur_index + 1) % 4];
		count += is_higher(old, new);
		cur_index++;
		if (cur_index > 3){ cur_index = cur_index % 4;}
	}
	printf("Depth increased %d times\n", count);


	return 1;
}
