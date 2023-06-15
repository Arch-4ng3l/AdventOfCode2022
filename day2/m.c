#include <stdio.h>

int calculateScore(char opponent, char response) {
    if (opponent == 'A' && response == 'Y') {
        return 8;
    } else if (opponent == 'B' && response == 'X') {
        return 1;
    } else if (opponent == 'C' && response == 'Z') {
        return 6;
    } else if (opponent == response) {
        return 3;
    } else {
        return 0;
    }
}

int main() {
    FILE *file = fopen("/home/moritz/Programming/C/aoc/day2/input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int totalScore = 0;
    char opponent, response;
	int count = 1; 
    while (fscanf(file, " %c %c", &opponent, &response) == 2) {
        int roundScore = calculateScore(opponent, response);
        totalScore += roundScore;
		count ++;
    }
	printf("%d\n", count);
    printf("Total score: %d\n", totalScore);

    fclose(file);
    return 0;
}
