/* code description: https://cs50.harvard.edu/x/2021/labs/2/
Summary: To make simple Scrabble scoring game */

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf ("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf ("Player 2 wins!\n");
    }
    else
    {
        printf ("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //This is the points based on alphabetical orders//
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    //calculate each words from string//
    int string_lenght = strlen (word);
    int score = 0;

    for (int n = 0; n < string_lenght; n++)
    {
        char x = word[n];
        char y = toupper(x);
        int ascii = (int)y;

        if ((ascii > 64) && (ascii < 91))
        {
            score += POINTS[ascii - 65];
        }
        else
        {
            continue;
        }
    }

    return score;
}
