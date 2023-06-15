// A ROCK     X    1
// B PAPER    Y    2
// C SCISSORS Z    3
// DRAW 3
// WIN 6 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charToInt(char a) {
	int value; 
	printf("%c", a);
	switch(a){
		case 'A':
			value = 1;
			return 1;
		case 'B':
			value = 2;
			return 2;
		case 'C':
			value = 3;
			return 3;
		case 'X':
			value = 1;
			return 1;
		case 'Y':
			value = 2;
			return 2;
		case 'Z':
			value = 3;
			return 3;
	}
	return 0;  
}

int points(int enemie, int player) {
	int score = player;	

	if(enemie == player) {
		score+= 3; 
		return score;
	} 

	switch(enemie) {
		case 1: 
			if(player == 2) 
				score += 6; 
			break;
		case 2:
			if(player == 3) 
				score += 6; 
			break;
		case 3:
			if(player == 1) 
				score += 6; 
			break;
	}

	return score; 
}
 
int main(void) {
	int score; 

	FILE *flptr;

	flptr = fopen("/home/moritz/Programming/C/aoc/day2/input.txt", "r");
	char enemie; 
	char player;
	int c;
	int p1; 
	int p2; 
	int count = 1; 
	while(c != EOF) {
		c = getc(flptr);
		if(c == EOF) {
			break;
		}
		printf("%d\n", c);
		fscanf(flptr, "%c %c", &enemie, &player);

		p1 = charToInt(enemie);

		p2 = charToInt(player);

		score += points(p1, p2);

		printf(" %d --- %d = %d   %d    ----> %d \n", p1, p2, points(p1, p2), count, score);

		count++;
	}

	printf("\n\n\n%d\n", score);


	//Part 2 
	



	//X  LOSE 
	//Y  DRAW
	//Z  WIN
	//
	//A ROCK 1
	// X SCISSOR 3
	// Y ROCK    1
	// Z PAPER   2
	//B PAPER
	// X ROCK    1
	// Y PAPER   2
	// Z SCISSOR 3
	//
	//C SCISSOR  
	// X PAPER   2
	// Y SCISSOR 3 
	// Z ROCK    1


	// A = 1 ROCK 
	// B = 2 PAPER
	// C = 3 SCISSOR
	printf("STARTING PART2\n");

	fseek(flptr, 0, SEEK_SET);

	int arrR[3][3] = {  {3, 1, 2},
						{1, 2, 3},
						{2, 3, 1}};
	p1 = 0; 
	p2 = 0;
	count = 1;
	c = 0; 
	int choose; 
	printf("STARTING LOOP\n");
	
	int score2 = 0;
	while(c != EOF) {


		if(count <= 2500) {
			fscanf(flptr, "%c %c", &enemie, &player);
			p1 = charToInt(enemie) -1;
			p2 = charToInt(player) -1; 
			//LOSE = 1
			//DRAW = 2
			//WIN  = 3
			choose = arrR[p1][p2];
			score2 += points(p1+1, choose);

			printf(" %d --- %d = %d   %d    ----> %d \n", p1+1, choose, points(p1+1, choose), count, score2);
		}
		else {
			break;
		}
		

		c = getc(flptr);
		count ++;
	}

	printf("PART2 SOLUTION \n%d\n", score2);



	fclose(flptr);
	return 0; 
}

