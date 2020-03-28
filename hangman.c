#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getWord.h"
#include "printStock.h"

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

int main(int argc, char **argv)
{
	clear();

	printf("Welcome to Hangman!\n");

	char word[100];
	char finalWord[100];
	char secretWord[100] = "\0";
	strcpy(word, getWord());
	strcpy(finalWord, word);

	int wordLen = strlen(word);
	for(int i=0; i<wordLen; i++)
	{
		secretWord[i] = '_';
		secretWord[i+1] = '\0';
	}

	char guess;
	char guessedLetters[100] = "\0";
	int guessesLeft = 8;
	char *pointToChar;
	int charIndex;

	printf("The secret word has %d letters\n", wordLen);
	printf("%s\n", secretWord);

	int lettersFound = 0;

	while(guessesLeft > 0)
	{
		printf("Guess a letter: ");
		guess = getchar();
		getchar();
		pointToChar = strchr(word, guess);

		if(strchr(guessedLetters, guess) != NULL)
		{
			printf("You have already guessed that\n\n");
			continue;
		}
		else
		{
			strncat(guessedLetters, &guess, 1);
			strcat(guessedLetters, "\0");
		}

		if(pointToChar == NULL)
		{
			guessesLeft--;
			printf("Wrong! %d guesses left\n", guessesLeft);
			printStock(guessesLeft);
			printf("%s\n", secretWord);
			printf("\n\n");


			if(guessesLeft == 0)
			{
				printf("You are out of guesses :(\n");
				printf("The word was %s\n", finalWord);
			}
		}
		else
		{
			printf("You got a letter!\n");

			while((pointToChar = strchr(word, guess)) != NULL)
			{
				lettersFound++;

				int index1 = 0;
				int index2 = 0;
				char wordPart1[100] = "\0";
				char wordPart2[100] = "\0";
				char secretWordPart1[100] = "\0";
				char secretWordPart2[100] = "\0";
				char *pointToWord = word;
							
				index1 = pointToChar - pointToWord;
				index2 = index1 + 1;
					
				if(index1 == 0)	
				{
					wordPart1[0] = '\0';
					secretWordPart1[0] = '\0';
				}
				else
				{
					for(int a=0; a<index1; a++)
					{
						wordPart1[a] = word[a];
						wordPart1[a+1] = '\0';
						
						secretWordPart1[a] = secretWord[a];
						secretWordPart1[a+1] = '\0';
					}
				}
					
				int b = 0;
				if(index2 == strlen(word))	
				{
					wordPart2[0] = '\0';
					secretWordPart2[0] = '\0';
				}
				else
				{
					for(int a=index2; a<strlen(word); a++)
					{
						wordPart2[b] = word[a];
						secretWordPart2[b] = secretWord[a];
						b++;
						wordPart2[b] = '\0';
						secretWordPart2[b] = '\0';
					}
				}

				strcat(wordPart1, "_");
				strcat(wordPart1, wordPart2);
				strcpy(word, wordPart1);
				
				strncat(secretWordPart1, &guess,  1);
				strcat(secretWordPart1, secretWordPart2);
				strcpy(secretWord, secretWordPart1);
			}
			printf("%s\n\n", secretWord);

			if(lettersFound == wordLen)
			{
				printf("You guessed the word!\n");
				break;
			}
		}
	}
}
