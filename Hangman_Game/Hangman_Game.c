#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define Max_tries 6
#define Max_word_len 50

void displayHangman(int tries)
{
    char *hangmanpart[]={"   _______",    "   |     |",
                         "   |     0",    "   |    /|\\"
                        ,"   |     |",    "   |    / \\", "   |"};
    printf("\n");          
    for (int i = 0 ; i <= tries ; i++)
                        {
        printf("%s\n",hangmanpart[i]);
    }
    printf("tries : %d\n",tries);
}

void displayword(char word[], bool guessed[])
{
    printf("word : ");
    for (int i = 0 ; word[i]!='\0' ; i++)
    {
        if (guessed[word[i] - 'a'])
        {
            printf("%c ",word[i]);
        }else
        {
            printf("_ ");
        }
    }
    printf("\n");
}


int main()
{
    srand(time(NULL));
    char *words[Max_word_len]={"pizza","elephant","beach",
                                "clubs","greater", "house"};
    int wordIndex=rand() % 6;
    char *secretWord=words[wordIndex];
    int wordlen = strlen(secretWord);
    bool guessedLetter[26]={false};
    char guessedword[Max_word_len]={0};

    printf("Welcom to hangman !\n");
    int tries = 0;
    while (tries <= Max_tries)
    {
        printf("\n");
        displayword(secretWord,guessedLetter);
        displayHangman(tries);

        char guess;
        printf("Enter letter :");
        scanf(" %c", &guess);
        guess = tolower(guess);
        if (guessedLetter[guess - 'a'])
        {
            printf("You've already chose this letter Try again. \n");
        }
        guessedLetter[guess - 'a'] = true;
        bool found = false;
        for (int i=0;i<wordlen;i++)
        {
            if(secretWord[i]==guess)
            {
                found = true;
                guessedword[i] = guess; 
            }
        }
        guessedword[wordlen]='\0';
        if (found)
        {
            printf("Great you've found a letter. \n");
        }else
        {
            printf("sorry the letter you chose is not in the word \n");
            tries++;
        }
        if (strcmp(guessedword,secretWord) == 0)
        {
            printf("Great you've found the Word. \n");
            printf("You Won !\n");
            return 0;
        }
        if (tries >= Max_tries)
        {
            printf("You lose !\n");
            printf("the word is %s", secretWord);
        }
    }
    return 0;
}