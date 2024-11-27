#pragma once

typedef struct Image
{
    int value;
    float* pixels;
} Image;

extern const int size;
extern const int max_char;

Image* images_from_csv(const char* filename, int image_number);
void print_image(const Image image);