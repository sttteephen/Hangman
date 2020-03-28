# Hangman

This is a text based version of hangman written in C.

## Usage 

The program chooses a random word from a text file. It will reveal how long the word is and prompt the user to guess a character.

If right the word will be displayed with the guessed character revealed.

If wrong the program will tell you how many guesses you have left and print the current state of the stick man which will progress with each wrong guess.

The user is allowed 8 wrong guesses before the game ends.

## Build from Source

The program was built using Microsoft (R) C/C++ Optimizing Compiler Version 19.24.28316 for x86. It can be compiled with the following command:
```bash
$ cl hangman.c printStock.c getWord.c
```
Using the makefile command:
```bash
$ nmake hangman
```
In GCC the program can be built using:
```bash
$ gcc hangman.c printStock.c getWord.c -o hangman
```
