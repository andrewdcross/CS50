#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed; // taking RGB values
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // taking the mean value of RGB and returning for new pixels
            int average = round((red + green + blue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // applying sepia formula given in pset
            int sepRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (sepRed > 255)
            {
                sepRed = 255;
            }

            int sepGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sepGreen > 255)
            {
                sepGreen = 255;
            }

            int sepBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepBlue > 255)
            {
                sepBlue = 255;
            }

            // writing new values to file
            image[i][j].rgbtRed = sepRed;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtBlue = sepBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // taking a temp variable for half the image
            RGBTRIPLE temp = image[i][j];
            // writing the new left half pixel values from the old right half of values
            image[i][j] = image[i][width - 1 - j];
            // taking new right half from temp file
            image[i][width - 1 - j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE arr[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = image[i][j];
        }
    }
    float r, b, g;
    float counter = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k < 2; k++) // iterating over +/- 1 from each i
            {
                for (int l = -1; l < 2; l++) // iterating +/- 1 from each j
                {
                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1)
                    {
                        // mega expression to cover corners, edges and inner pixels
                        // if [i+/-k] and [j+/-l] exist
                        r += arr[i + k][j + l].rgbtRed;
                        b += arr[i + k][j + l].rgbtBlue;
                        g += arr[i + k][j + l].rgbtGreen;
                        counter++; // only taking 4, 6 or 9 values for corner, edge etc
                    }

                }
            }
            r = r / counter;
            b = b / counter;
            g = g / counter;
            if (r > 255) // conditions to make max values 255 - needed?
            {
                r = 255;
            }
            if (r < 0) // min values 0
            {
                r = 0;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (g < 0)
            {
                g = 0;
            }
            if (b > 255)
            {
                b = 255;
            }
            if (b < 0)
            {
                b = 0;
            }
            image[i][j].rgbtRed = round(r); // int rounding values
            image[i][j].rgbtBlue = round(b);
            image[i][j].rgbtGreen = round(g);
            counter = 0; // resetting variables
            r = 0;
            g = 0;
            b = 0;
        }
    }
    return;
}
