#include "getWord.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* getWord()
{
	FILE *wordsList;
	wordsList = fopen("words.txt", "r");

	int range = 0;
	char letter;

	while((letter = getc(wordsList)) != EOF)
	{
		if(letter == '\n')
			range++;
	}
	fclose(wordsList);

	srand(time(0));
	int randIndex = (rand()%(range+1));

	wordsList = fopen("words.txt", "r");

	int j = 0;
	int i = 0;
	char word[100];
	memset(word, '\0', sizeof(word));
	while((letter = getc(wordsList)) != EOF)
	{
		if(letter != '\n')
		{
			word[i] = letter;
			strcat(word, "\0");
			i++;
		}
		else if(letter == '\n' && j == randIndex)
		{
			j++;
			i = 0;
			break;
		}
		else if(letter == '\n')
		{
			j++;
			memset(word, '\0', sizeof(word));
			i = 0;
		}
	}
	fclose(wordsList);

	return word;
}
