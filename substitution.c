/* code description: https://cs50.harvard.edu/x/2021/psets/2/substitution/
Summary: To encrypt using substitution system */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    string key1 = argv[1];

    //check for only 2 arguments//
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //check key length, must 26 lenght//
    if (strlen(key1) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i=0; i < strlen(key1); i++)
    {
        //check for non alphabet//
        if (!(isalpha(key1[i])))
        {
            printf("Key must contain only letters.\n");
            return 1;
        }

        //convert all word to uppercase to make encryption easier//
        else
        {
            key1[i] = toupper (key1[i]);
        }

        //check for not repeated word//
        for (int j=0; j < i; j++)
        {
            if (key1[i] == key1[j])
            {
                printf("Key must not contain repeated letters.\n");
                return 1;
            }
        }
    }

    //ask input//
    string input1 = get_string("plaintext: ");
    string input2 = input1;

    //check if the word is lower or uppercase//
    int checker[25];
    for (int s = 0; s < strlen (input1); s++)
    {
        if (isupper(input1[s]) == 0)
        {
            checker[s] = 0; //false

            //convert to uppercase to make encryption easier//
            input1[s] = toupper (input1[s]);
        }
        else
        {
            checker[s] = 1; //true
        }

        //printf("Input %d: %c is %d\n", s, input1[s], checker[s]); //debug//

    }

    //printf("word is %s\n", input1); //debug//

    //CONVERTTTT//
    int new_ascii = 0;
    printf("ciphertext: ");

    for (int k = 0; k < strlen(input1); k++)
    {
        char x = input1[k];
        int ascii = (int) x;

        //check if it's alphabet or not//
        if (isalpha(x))
        {
            ascii -=  65;
            new_ascii = key1[ascii];

            //restore to upper/lowercase
            if (checker[k]==0)
            {
               new_ascii = (int) tolower ((char) new_ascii); //we use tolower cause all word has converted to upper
            }

        }
        else //if not just continue
        {
            new_ascii = ascii;
        }

        printf("%c", (char) new_ascii);
    }

    printf("\n");

    return 0;
}

