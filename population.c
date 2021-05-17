#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int population, finalPop;

    // Taking starting population
    do
    {
        population = get_int("Enter initial population: ");
    }
    while (population < 9);;

    // Taking final population
    do
    {
        finalPop = get_int("Enter final population: ");
    }
    while (finalPop < population);;
    
    if (finalPop == population)
    {
        printf("Years: 0\n");
    }
    else
    {
        // Initialising years increment
        int years = 0;

        // Running the birth/death calculation
        do
        {
            population = population + population / 3 - population / 4;
            years++;
        }
        while (population < finalPop); // until we reach desired population

        //Printing results
        printf("Years: %i\n", years);
    }
}
