/* code description: https://cs50.harvard.edu/x/2021/psets/2/caesar/
Summary: To encrypt using caesar system */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int encryptor();

int main(int argc, string argv[])
{
    //process command line argument//

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++) //checking if it only accept digit
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        string input = get_string("plaintext: ");//ask input//
        int number = (atoi (argv[1]) % 26); //make sure its on alphabetical limit
        encryptor(input, number); //pass to encryptor function//
    }

}

int encryptor (string input, int number)
{
    int len = strlen(input);
    int new_ascii = 0;
    printf("ciphertext: ");
    //encrypt every single char from input string//
    for (int i = 0; i < len; i++)
    {
        char x = input[i];
        int ascii = (int) x;
        if (isalpha(x)) //chech if its alphabet
        {
            if (isupper(x)) //check if uppercase
            {
                new_ascii = (ascii + number) % 90;

                //check if it is on right order//
                if (new_ascii == 0)
                {
                    new_ascii += 90;
                }
                else if ((new_ascii < 64))
                {
                    new_ascii += 64;
                }
            }
            else //if not then its lowercaser
            {
                new_ascii = (ascii + number) % 122;

                //check if it is on right order//
                if (new_ascii == 0)
                {
                    new_ascii += 122;
                }
                else if ((new_ascii < 96))
                {
                    new_ascii += 96;
                }
            }
        }
        else //if not then continue
        {
            new_ascii = ascii;
        }


        //print
        printf("%c", (char) new_ascii);
    }
    printf("\n");
    return (char) new_ascii;
}
