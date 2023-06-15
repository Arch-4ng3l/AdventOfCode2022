#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int max; 
	int current; 
	FILE *flptr;
	flptr = fopen("/home/moritz/Programming/C/aoc/day1/input.txt", "r");
	if(flptr == NULL) {
		printf("ERROR");
		exit(1);
	}
	char fileContent[100];
	char prev[100];

	while(1) {

		fgets(fileContent, 100, flptr);
		current+= atoi(fileContent);

		if(strcmp(fileContent, "\n") == 0) {

			if(current > max) {
				max = current;
			}
			current = 0; 
		}
		if(strcmp(prev, fileContent)==0) {
			break;
		}
		memcpy(prev, fileContent, 100);
	}

	printf("\n %d \n", max);

	fclose(flptr);
}
