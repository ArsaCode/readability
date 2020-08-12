#include <stdio.h>
#include "cs50.h"
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
U.S Readability Calculator v1.0 - Developed by Arsalan Ghassemi
*/

// Variables and functions declarations

void getText();
void countLetters();
void countWords();
void countSentences();
void calculateReadability();
void displayResult();
int totalLetters;
int totalWords;
int totalSentences;
int grade;
string text;

/*
Hello ! This is the readability software made for the Problem Set 2 of CS50's Introduction to Computer Science course.

The user should input a text (a part of a book for example, or even a whole book).

The software works as follows :

1 . Get the users input
2 . Count the total number of letters in the text
3 . Count the total number of words in the text
4 . Count the total number of sentences in the text
5 . Calculates the average of total number of letters per 100 words and total number of sentences per 100 words
6 . Calculates the readability with the Coleman-Liau's index
7 . Display the U.S Grade readability for the user (outputs possible : "Before Grade 1, Grade 1 to Grade 16, Grade 16+").

Feel free to send any suggestions at contact@arsadevs.com 
*/

int main(void)

{
    text = get_string("Text :\n");
    countLetters();
    countWords();
    countSentences();
    calculateReadability();
    displayResult();
}

void countLetters()
// First function in order to count the letters
{
    int lettersCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        lettersCount++;
        if (isalpha(text[i]) == false)
        {
            lettersCount--;
        }
    }
    totalLetters = lettersCount;
}

void countWords()
// Second function in order to count the words
{
    int wordsCount = 1;
    for (int j = 0; j < strlen(text); j++)
    {
        if (isblank(text[j]))
        {
            wordsCount++;
        }
    }
    totalWords = wordsCount;
}

void countSentences()
// Third function in order to count the sentences
{
    int sentencesCount = 0;
    for (int w = 0; w < strlen(text); w++)
    {
        if (text[w] == '.' || text[w] == '!' || text[w] == '?')
        {
            sentencesCount++;
        }
    }
    totalSentences = sentencesCount;
}

void calculateReadability()
// Fourth function in order to calculate the Coleman Liau's index
{
    float a = (float) totalLetters * 100 / (float) totalWords;
    float b = (float) totalSentences * 100 / (float) totalWords;
    float index = 0.0588 * a - 0.296 * b - 15.8;
    grade = round(index);
}

void displayResult()
// Last function in order to display the appropriate result
{
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}