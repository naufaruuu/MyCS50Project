/* code description: https://cs50.harvard.edu/x/2021/psets/1/cash/
Summary: To calculate ammoun fo coins from dollar */

#include <stdio.h>
#include <math.h>


int main ()
{
    float dollar;
    float cents;
    int coin = 0;
    int  c25 = 0;
    int c10 = 0;
    int c5 = 0;
    int c1 = 0;

    //ask dollar ammount to user. make sure its positive integer//
    do
    {
        printf ("\tHow much your money?");
        scanf ("%f", &dollar);

        if (dollar <= 0)
        {
            printf ("\tInsert right value!\n");
        }
    }

    while (dollar <= 0);
    printf ("\n");


    //convert dollar to cents. Input math.h to use the functions//
    cents = round (dollar * 100);

    //Use while loop to  examine ammount of coin needed//
    while (cents >= 25)
    {
        cents -= 25;
        coin++;
        c25++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coin++;
        c10++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coin++;
        c5++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coin++;
        c1++;
    }

    //Show the conclusion//

    printf("\tYou have %i coins\n", coin);
    printf("\tThere are '%i' 25 cent coins, '%i' 10 cent coins, '%i' 5 cent coins, and '%i' 1 cent coins\n", c25, c10, c5, c1);


}
