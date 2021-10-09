/* code description: https://cs50.harvard.edu/x/2021/psets/1/mario/more/
Summary: To make Mario Stairs */

#include <stdio.h>
#include <cs50.h>

int height(void);

int main (void)
{
    int row, coloumn, cpart1, cpart2, cpart3;
    int n = height();
    int coloumnnum = 4 + 2 * (n -1);

    for (row=0; row < n ; row++)
    {
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

        for (cpart2=0; cpart2 < 2; cpart2++ )
           {
               printf (" ");
           }

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
            printf("input diluar rentang\n");
        }
    }
    while (n < 1 || n > 8);
    return n;

}
