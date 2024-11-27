#include "image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 28;
const int max_char = 2000; 

Image* images_from_csv(const char* filename, int image_number)
{
    FILE* image_file = fopen(filename, "r");
    char image_data[max_char];

    Image* images = malloc(sizeof(Image) * image_number);

    int image_count = 0;
    int pixel_count = 0;

    while (fgets(image_data, max_char, image_file) != NULL && image_count < image_number)
    {
        Image image = {
            .pixels = malloc(sizeof(float) * size * size),
            .value = -1,
        };

        pixel_count = 0;

        char* token = strtok(image_data, ",");

        if (!token)
        {
            break;
        }

        image.value = atoi(token);
        token = strtok(NULL, ","); // TODO, remove second strtok here
        printf("Reading image with value: %d\n", image.value);
        
        while (token != NULL)
        {
            image.pixels[pixel_count] = (float)atoi(token) / 255.0f;
            token = strtok(NULL, ",");
            pixel_count++;
        }

        images[image_count] = image;
        image_count++;
    }

    return images;
}

int index_from_pos(int y, int x)
{
    return y * size + x;
}

void print_image(const Image image)
{
    printf("Picture that represents number: %d\n", image.value);
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            double pixel_value = image.pixels[index_from_pos(i, k)];
            printf("%0.2f ", pixel_value);
        }
        printf("\n");
    }
}