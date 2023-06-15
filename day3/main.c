#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


char hashTable[100] = { 0 };

unsigned int hash(char a) {
		
	unsigned int hashValue; 
	
	hashValue = a * 20329; 
	hashValue = (hashValue * a + 232) * 122 + 32; 
	hashValue = hashValue * 2; 
	hashValue++; 
	hashValue = hashValue%100; 
	
	return hashValue;

}

int add(char a) {
	unsigned int index = hash(a);
	if(hashTable[index] == ' ') {
		hashTable[index] = a;
	}
	else {
		int count = index;
		
		for(int i = 0; i < 100; i++) {
			if(hashTable[count] == ' ') {
				hashTable[count] = a;
				break;
			}

			count = (count +1) % 100;
		}
	}
	return 0; 
}
int search(char a) {
	unsigned long index = hash(a); 

	if(hashTable[index] == a) return 1; 
	else {
		int count = index; 
		for(int i = 0; i < 100; i++) {
			if(hashTable[count] == a) {
				return 1;
			}
			count = (count + 1) % 100; 
		}
	}
	return 0;
}

void clearTable(){
	for(int i = 0; i < 100; i++) {
		hashTable[i] = ' ';
	}
}
int main(void) {
	
	FILE *flptr; 
	flptr = fopen("/home/moritz/Programming/C/aoc/day3/input.txt", "r");


	int c = 0; 
	int count = 0; 
	unsigned long prio = 0; 
	printf("#######PART 1#######\n");
	while(count < 300) {
		char rucksack1[256] = { 0 }; 
		char rucksack2[256] = { 0 };
		char buffer[256] = { 0 };
		count++; 
		c = fgetc(flptr); 
		clearTable();
		fscanf(flptr, "%s", buffer);
				
		printf("%lu\n", prio);

		for(int i = 0; i <= strlen(buffer)/2-1; i++) {
			rucksack1[i] = buffer[i]; 	
		}
		rucksack1[strlen(buffer)/2] = '\0';
		strncpy(rucksack2, buffer + strlen(buffer)/2, strlen(buffer));
		rucksack2[strlen(buffer)] = '\0';
		

		for(int i = 0; i < strlen(rucksack1); i++) {
			add(rucksack1[i]); 
		}
		int sharedChar = { 0 };  
		for(int i = 0; i < strlen(rucksack2); i++) {
			if(search(rucksack2[i])) {
				sharedChar = i; 
				break;
			}
		}
		
		printf("------------------%d------------------------\n", count);
		if(islower(rucksack2[sharedChar])) {
			prio+= rucksack2[sharedChar]-96;
			printf("CHAR: %c  VALUE : %d prio : %lu\n",rucksack2[sharedChar], rucksack2[sharedChar], prio);
		} else if(rucksack2[sharedChar] != ' ') {
			prio+= rucksack2[sharedChar] -64+26;
			printf("CHAR: %c  VALUE : %d prio : %lu\n",rucksack2[sharedChar], rucksack2[sharedChar], prio);
		}

		printf("%s\n", buffer);

		printf("--------------------------------------------\n");

	}

	fclose(flptr); 

	printf("\n\n\n\n#######PART 2#######\n\n\n\n");
	prio = 0; 	
	flptr = fopen("/home/moritz/Programming/C/aoc/day3/input.txt", "r");
	
	char sharedChars[100];
	int ind, res; 
	char buffer[256]; 
	count = 0; 
	int br; 
	while(count < 100) {
		br = 0; 
		c = getc(flptr);
		count++; 
		ind = 0; 	
		fscanf(flptr, "%s", buffer);
		clearTable();
		for(int i = 0; i < strlen(buffer); i++) {
			add(buffer[i]);
		}
		printf("1: %s\n", buffer);
		c = getc(flptr);
		fscanf(flptr, "%s", buffer);
		for(int i = 0; i < strlen(buffer); i++) {
			if(search(buffer[i])) {
				sharedChars[ind] = buffer[i]; 
				ind++; 
			}
		}
		
		printf("2: %s\n", buffer);
		c = getc(flptr);
		fscanf(flptr, "%s", buffer);
		for(int i = 0; i < strlen(buffer); i++) {
			for(int j = 0; j < ind; j++) {
				if(buffer[i] == sharedChars[j]) {
					res = i; 
					br = 1; 
					break;
				}
			}
			if(br) break; 
		}
			
		printf("3: %s\n", buffer);
		printf("%c\n", buffer[res]);
		printf("---------------------------------------------\n");
		if(islower(buffer[res])) {
			prio += buffer[res]-96;
			printf("CHAR: %c  VALUE : %d prio : %lu\n",buffer[res], buffer[res], prio);
		} else if(buffer[res] != ' ') {
			prio += buffer[res] -64+26;
			printf("CHAR: %c  VALUE : %d prio : %lu\n",buffer[res], buffer[res], prio);
		}
		printf("---------------------------------------------\n");


		
	}
	fclose(flptr);


	printf("%lu\n", prio);
}
