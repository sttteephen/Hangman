#include "getWord.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//returns a random word from a text file
char* getWord()
{
	//open the text file with the list of words
	FILE *wordsList;
	wordsList = fopen("words.txt", "r");

	int range = 0;
	char letter;

	//get the number  of words in the file
	while((letter = getc(wordsList)) != EOF)
	{
		if(letter == '\n')
			range++;
	}

	//get a random number within the range of 1 to the amount of words in the file to be used as the index for a word
	srand(time(0));
	int randIndex = (rand()%(range+1));

	wordsList = fopen("words.txt", "r");

	int placeInFile = 0;
	int i = 0;
	
	//allocate memory for the word
	char* word_ptr = (char*)malloc(100*sizeof(char));
	memset(word_ptr, '\0', sizeof(word_ptr));

	//read throught the text file and store the indexed word
	while((letter = getc(wordsList)) != EOF)
	{
		if(letter != '\n')
		{
			word_ptr[i] = letter;
			strcat(word_ptr, "\0");
			i++;
		}
		else if(letter == '\n' && placeInFile == randIndex)
		{
			break;
		}
		else if(letter == '\n')
		{
			placeInFile++;
			memset(word_ptr, '\0', sizeof(word_ptr));
			i = 0;
		}
	}

	//close the text file
	fclose(wordsList);

	//return the pointer to the word
	return word_ptr;
}
