#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int words = 1; // setting initial word count as 1 to overcome bug
    int sentences = 0;
    string text = get_string("Text: ");
    int letters = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0) // operation for counting letters only (A-Z, a-z)
        {
            letters++;
        }
        
        else if (text[i] == ' ') // increasing wordcount by spaces
        {
            words++;
        }
        
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') // increasing sentences with '.', '!' or '?' as end of sentence
        {
            sentences++;
        }
    }
    
    float L = (float) letters / (float) words * 100.0; 
    float S = (float) sentences / (float) words * 100.0;
    float index = round(0.0588 * L - 0.296 * S - 15.8); // calculation for Coleman-Liau Index
    
    if (index < 1) // handling below grade 1 cases
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16) // 16+ cases 
    {
        printf("Grade 16+\n");
    }
    
    else // all other cases
    {
        printf("Grade %.0f\n", index);
    }

}
