#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 0;
    float n;
    
    do
    {
        n = get_float("Change owed: ");
    }
    while (n <= 0);

    n = n * 100;
    n = round(n);
    
    while (n > 0)
    {
        if (n >= 25)
        {
            n = n - 25;
            count++;
        }
        
        else if (n >= 10)
        {
            n = n - 10;
            count++;
        }
        
        else if (n >= 5)
        {
            n = n - 5;
            count++;
        }
        
        else if (n >= 1)
        {
            n = n - 1;
            count++;
        }
    }
    
    printf("Coins used: %i\n", count);
    
}
