#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getWord.h"
#include "printStock.h"

#define STR_LEN 100

//clear the screen
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

	char word[STR_LEN];
	char finalWord[STR_LEN];
	char secretWord[STR_LEN] = "\0";

	//get a random word for user to guess
	char* ptrToWord = getWord();
	strcpy(word, ptrToWord);
	strcpy(finalWord, word);
	free(ptrToWord);

	//create a string, the length of the word to be guessed, using '_' characters
	int wordLen = strlen(word);
	for(int i=0; i<wordLen; i++)
	{
		secretWord[i] = '_';
		secretWord[i+1] = '\0';
	}

	char guess;
	char guessedLetters[STR_LEN] = "\0";
	int guessesLeft = 8;
	char *pointToChar;
	int charIndex;

	printf("The secret word has %d letters\n", wordLen);
	printf("%s\n", secretWord);

	int lettersFound = 0;

	//loop whilst the player still has guesses left
	while(guessesLeft > 0)
	{
		//get a guess from the user
		printf("Guess a letter: ");
		guess = getchar();
		getchar();
		pointToChar = strchr(word, guess);

		if(strchr(guessedLetters, guess) != NULL)
		{
			//tell them if the have already guesssed that letter
			printf("You have already guessed that\n\n");
			continue;
		}
		else
		{	
			//add guess to string of guessed letters
			strncat(guessedLetters, &guess, 1);
			strcat(guessedLetters, "\0");
		}

		if(pointToChar == NULL)
		{
			//display if guess is wrong
			guessesLeft--;
			printf("Wrong! %d guesses left\n", guessesLeft);
			printStock(guessesLeft);
			printf("%s\n", secretWord);
			printf("\n\n");

			//display if out of guesses
			if(guessesLeft == 0)
			{
				printf("You are out of guesses :(\n");
				printf("The word was %s\n", finalWord);
			}
		}
		else
		{
			printf("You got a letter!\n");

			//if the guess is correct display the correctly guessed letter in every place it occurs in the word
			while((pointToChar = strchr(word, guess)) != NULL)
			{
				lettersFound++;

				int index1 = 0;
				int index2 = 0;
				char wordPart1[STR_LEN] = "\0";
				char wordPart2[STR_LEN] = "\0";
				char secretWordPart1[STR_LEN] = "\0";
				char secretWordPart2[STR_LEN] = "\0";
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
				//display if all letters have been found
				printf("You guessed the word!\n");
				break;
			}
		}
	}
}
