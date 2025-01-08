#include <iostream>

#define NUM_ROWS 2
#define NUM_COLS 2
#define NUM_COLOR_CHANNELS 3

int main()
{
    // int originalImage[2][3][2] = {{255, 0, 0},
    //                               {0, 255, 0},
    //                               {0, 0, 255},
    //                               {255, 255, 0}};

    int originalImage[NUM_ROWS][NUM_COLS][NUM_COLOR_CHANNELS] =
        {
            {{255, 0, 0}, {0, 255, 0}},
            {{0, 0, 255}, {255, 255, 0}}};

    float grayScaleFilter[3] = {0.299, 0.587, 0.114};

    printf("-------------- BEFORE --------------\r\n");
    // Loop through each pixel and each color channel
    for (int currentRow = 0; currentRow < NUM_ROWS; currentRow++)
    {
        for (int currentCol = 0; currentCol < NUM_COLS; currentCol++)
        {
            // Print RGB values for each color channel
            printf("Pixel (%d, %d) : ", currentRow, currentCol);
            for (int currentColorChannel = 0; currentColorChannel < NUM_COLOR_CHANNELS; currentColorChannel++)
            {
                // Print the value of the current color channel
                if (currentColorChannel == 0)
                {
                    printf("Red = %d, ", originalImage[currentRow][currentCol][currentColorChannel]);
                }
                else if (currentColorChannel == 1)
                {
                    printf("Green = %d, ", originalImage[currentRow][currentCol][currentColorChannel]);
                }
                else if (currentColorChannel == 2)
                {
                    printf("Blue = %d", originalImage[currentRow][currentCol][currentColorChannel]);
                }
            }
            printf("\n");
        }
    }

    // Loop through each pixel and each color channel
    //  for (int currentRow = 0; currentRow < NUM_ROWS; currentRow++)
    //  {
    // for (int currentCol = 0; currentCol < NUM_COLS; currentCol++)
    //   {

    // My attempt
    // Grayscale value = 0.299 * Red + 0.587 * Green + 0.114 * Blue

    // originalImage[currentRow][currentCol][0] = originalImage[currentRow][currentCol][0] * grayScaleFilter[0]; // red
    // originalImage[currentRow][currentCol][1] = originalImage[currentRow][currentCol][1] * grayScaleFilter[1]; // green
    // originalImage[currentRow][currentCol][2] = originalImage[currentRow][currentCol][2] * grayScaleFilter[2]; // blue

    // The solution
    // Calculate the grayscale value using the weighted sum of the RGB channels
    // float grayValue = originalImage[currentRow][currentCol][0] * grayScaleFilter[0] +
    //                   originalImage[currentRow][currentCol][1] * grayScaleFilter[1] +
    //                   originalImage[currentRow][currentCol][2] * grayScaleFilter[2];

    // Optionally, you can assign the grayscale value to all channels to get a grayscale image
    // originalImage[currentRow][currentCol][0] = grayValue; // red
    // originalImage[currentRow][currentCol][1] = grayValue; // green
    // originalImage[currentRow][currentCol][2] = grayValue; // blue
    //}
    // }

    for (int currentRow = 0; currentRow < NUM_ROWS; currentRow++)
    {
        for (int currentCol = 0; currentCol < NUM_COLS; currentCol++)
        {
            // Variable to store the grayscale value for the current pixel
            float grayValue = 0.0;

            // Iterate over the color channels (Red, Green, Blue)
            for (int currentColorChannel = 0; currentColorChannel < NUM_COLOR_CHANNELS; currentColorChannel++)
            {
                // Multiply each color channel by its respective grayscale weight
                grayValue += originalImage[currentRow][currentCol][currentColorChannel] * grayScaleFilter[currentColorChannel];

                // Store the new grayscale value into the originalImage array
                originalImage[currentRow][currentCol][currentColorChannel] = grayValue;
            }

            // Now set all color channels to the computed grayscale value
            // for (int currentColorChannel = 0; currentColorChannel < NUM_COLOR_CHANNELS; currentColorChannel++)
            // {
            //     originalImage[currentRow][currentCol][currentColorChannel] = grayValue;
            // }
        }
    }

    printf("\n-------------- AFTER --------------\r\n");

    // Loop through each pixel and each color channel
    for (int currentRow = 0; currentRow < NUM_ROWS; currentRow++)
    {
        for (int currentCol = 0; currentCol < NUM_COLS; currentCol++)
        {
            printf("Pixel (%d, %d) : ", currentRow, currentCol);

            for (int currentColorChannel = 0; currentColorChannel < NUM_COLOR_CHANNELS; currentColorChannel++)
            {
                // Print the value of the current color channel
                if (currentColorChannel == 0)
                {
                    printf("Red = %d, ", originalImage[currentRow][currentCol][currentColorChannel]);
                }
                else if (currentColorChannel == 1)
                {
                    printf("Green = %d, ", originalImage[currentRow][currentCol][currentColorChannel]);
                }
                else if (currentColorChannel == 2)
                {
                    printf("Blue = %d", originalImage[currentRow][currentCol][currentColorChannel]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}