/* code description: https://cs50.harvard.edu/x/2021/psets/1/mario/more/
Summary: To make Mario Stairs 1-8 */

#include <stdio.h>
#include <cs50.h>

//prototype
int height(void);

int main (void)
{
    int row, coloumn, cpart1, cpart2, cpart3;
    int n = height(); //passing array
    int coloumnnum = 4 + 2 * (n -1);

    for (row=0; row < n ; row++)
    {
        //left side
        for (cpart1=0; cpart1 < n; cpart1++)
           {
                if (cpart1 + row < n - 1 )
                {
                    printf(" ");
                }

                else
                {
                    printf("#");
                }
           }

         //center side
        for (cpart2=0; cpart2 < 2; cpart2++ ) 
           {
               printf (" ");
           }

        //right side
        for (cpart3=0; cpart3 <  row +1; cpart3++)
           {
               printf ("#");
           }

        printf ("\n");
    }
}

int height(void)
{
    int n;
    do
    {
        printf ("Insert Height: ");
        scanf (" %d", &n);
        if (n < 1 || n > 8)
        {
            printf("Outranged Input!\n");
        }
    }
    while (n < 1 || n > 8);
    return n;
}
