/* code description: https://cs50.harvard.edu/x/2021/psets/1/credit/
Summary: To analyze credit card type */

#include <stdio.h>

int main (void){

    unsigned long long credit_number;
    unsigned long long credit_number_backup;
    int first_cc_a, first_cc_b;
    int card_digit = 0;
    int card_digit_backup = 0;
    int odd = 0;
    int even = 0;
    int odd_total = 0;
    int even_total = 0;
    int g1, g2;
    int total, total_final; 
    
    //ask cc number//
    printf ("Insert Your Card Number: ");
    scanf (" %llu", &credit_number);
    credit_number_backup = credit_number; //make backup cuz cc number will be empty after line 27

    while (credit_number>0)
    {
        credit_number=credit_number/10; //calculate cc number digit
        card_digit++;
    }

    //Check card checksum//
    credit_number = credit_number_backup; //restore empty cc number
    credit_number_backup = credit_number;

    while (credit_number>0)
    {
        odd = credit_number%10; //operation start from backwards
        odd_total = odd_total + odd;
        credit_number = credit_number/10; //fist is odd number

        even = (credit_number%10) * 2; //even need to multiply *2
        credit_number = credit_number/10; //second is even number

        g1 = even % 10;
        g2 = (even - g1) / 10;
        even_total = even_total + g1 + g2; //if has 2 digits, it has to separated and summed
    }

    total = odd_total + even_total;
    total_final = total % 10; //Only need last digit



    //Identify first 2 number //

    credit_number = 0;
    credit_number = credit_number_backup; //nullify 


    if (card_digit == 15)
    {
        first_cc_a = credit_number / 10000000000000; //13
    }
    else if (card_digit == 16)
    {
        first_cc_a = credit_number / 100000000000000; //14
        first_cc_b = credit_number / 1000000000000000; //16
    }
    else if (card_digit == 13)
    {
        first_cc_b = credit_number / 1000000000000; //12
    }

    //PRINT//

    if (credit_number < 1)
     {
        printf("INVALID\n"); //ask positive integer
    }

    else if (total_final != 0) //Last digit need to be 0
    {
        printf ("INVALID\n");
    }
    else if (card_digit != 13 && card_digit !=15 && card_digit !=16)
    {
        printf("INVALID\n");
    }
    else if ((card_digit == 15) && (first_cc_a == 34 || first_cc_a == 37))
    {
        printf ("AMEX\n");
    }
    else if ((card_digit == 16) && (first_cc_a == 51 || first_cc_a == 52 || first_cc_a == 53 || first_cc_a == 54 || first_cc_a == 55 ))
    {
        printf ("MASTERCARD\n");
    }
    else if ((first_cc_b == 4) && (card_digit == 13 || card_digit == 16))
    {
        printf ("VISA\n");
    }
    else
    {
        printf ("INVALID\n");
    }




}


