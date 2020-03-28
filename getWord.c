#include "getWord.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* getWord()
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
	char* word_ptr = (char*)malloc(100*sizeof(char));
	memset(word_ptr, '\0', sizeof(word_ptr));
	while((letter = getc(wordsList)) != EOF)
	{
		if(letter != '\n')
		{
			word_ptr[i] = letter;
			strcat(word_ptr, "\0");
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
			memset(word_ptr, '\0', sizeof(word_ptr));
			i = 0;
		}
	}
	fclose(wordsList);

	return word_ptr;
}
