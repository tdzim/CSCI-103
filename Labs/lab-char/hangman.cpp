#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int processGuess(char* word, const char* targetWord, char guess, int count, int wordlength);

const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
    srand(time(0));
    char guess;
    bool wordGuessed = false;
    int numTurns = 10;
    int count = 0;
    char word[80];

    const char* targetWord = wordBank[rand() % numWords];
    
    // Set wordlength to strlen(*targetWord)
    int wordlength = strlen(targetWord);
    
    // Initialize word to *'s
    for (int i = 0; i < wordlength; i++)
    {
        word[i] = '*';
    }

    while (!wordGuessed && numTurns > 0)
    {
        // Prompt
        cout << "Current word:  ";
        for (int j = 0; j < wordlength; j++)
        {
            cout << word[j];
        }
        cout << endl;
        cout << numTurns << " remain...Enter a letter to guess:" << endl;
        
        cin >> guess;
        
        if (processGuess(word, targetWord, guess, count, wordlength) == 0)
        {
            numTurns--;
        }
        
        if (strcmp(word, targetWord) == 0)
        {
            wordGuessed = true;
        }
        for (int l = 0; l < wordlength; l++)
        {
            if (word[l] != targetWord[l])
            {
                wordGuessed = false;
                break;
            }
            else
            {
                wordGuessed = true;
            }
        }
    }
    
    if (wordGuessed)
    {
        cout << "The word was: " << targetWord << ". You win!" << endl;
    }
    else
    {
        cout << "Too many turns...You lose!" << endl;
    }
    return 0;
}

int processGuess(char* word, const char* targetWord, char guess, int count, int wordlength)
{
    count = 0;
    for (int k = 0; k < wordlength; k++)
    {
        if (guess == targetWord[k])
        {
            word[k] = targetWord[k];
            count++;
        }
    }
    return count;
}
