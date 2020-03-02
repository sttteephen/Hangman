#include <stdio.h>
#include <stdlib.h>

void printStock(int guessesLeft)
{
	switch(guessesLeft)
	{
		case 8 :
			printf("____\n");
			printf("|   |\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 7 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 6 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|   |\n");
			printf("|\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 5 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|  /|\n");
			printf("|\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 4 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|  /|\\\n");
			printf("|\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 3 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|  /|\\\n");
			printf("|  /\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 2 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|  /|\\\n");
			printf("|  / \\\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 1 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|  /|\\\n");
			printf("|  / \\_\n");
			printf("|\n");
			printf("+------\n");
			break;

		case 0 :
			printf("____\n");
			printf("|   |\n");
			printf("|   0\n");
			printf("|  /|\\\n");
			printf("| _/ \\_\n");
			printf("|\n");
			printf("+------\n");
			break;
	}
}

/*
____
|   |
|   0
|  /|\
| _/ \_
|
+------
*/
