// Do we pronounce it "see-zer" or "kuy-sar"?

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) // checking for 1 cmd-line input
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    if (argv[1] == NULL) // handling lack of argv[1]
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key = atoi(argv[1]); // converting cmd-line input to int
    
    if (key <= 0) // k only positive integer
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    else
    {
        string plaintext = get_string("plaintext: "); //taking in plaintext
        char ciphertext[strlen(plaintext) + 1]; // init cipher, probbaly a better way to do this
        for (int i = 0; i < strlen(plaintext); i++) //iterating over length of string
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // handling uppercase chars and overflow
            {
                ciphertext[i] = ((plaintext[i] + key) - 'A') % 26 + 'A'; 
            }
            
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') // handling lowercase
            {
                ciphertext[i] = ((plaintext[i] + key) - 'a') % 26 + 'a';
            }
            else // handling all else (punctuation etc.)
            {
                ciphertext[i] = plaintext[i];
            }
        }
        
        printf("ciphertext: %s\n", ciphertext); // printing ciphertext
        return 0;
    }

}
