#include <stdio.h>

// Calling functions first
int getHeight();
void draw(int height);

int main(void)
{
    int height = getHeight();
    draw(height);
}

int getHeight() // Setting function for getting height
{
    int height;
    do
    {
        printf("Height: \n"); // Prompting user for height
        scanf("%d", &height);
    }
    while (height < 1 || height > 8); // Ensuring only 1-8 can be used

    return height;
}

void draw(int height) // Drawing the stairs
{
    for (int i = 1; i < height + 1; i++) 
    {
        for (int spaces = i; spaces < height; spaces++) // Printing spaces per line, spaces = line no. - 1
        {
            printf(" ");
        }

        for (int hashes = height + i; hashes > height; hashes--) // Printing hashes per line, hashes = line no.
        {
            printf("#");
        }
        printf("\n");
    }
}
