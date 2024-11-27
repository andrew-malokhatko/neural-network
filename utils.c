#include "utils.h"
#include <math.h>
#include <stdlib.h>

// Browse the internet for more information, this code just follows default softmax formula
float softmax(int len, const float* vector, float item)
{
    static double sum;

    if (vector)
    {
        sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += exp(vector[i]);
        }
    }

    return exp(item) / sum;
}

float* softmax_vector(int len, const float* vector)
{
    if (!vector || len <= 0)
    {
        return NULL;
    }

    float* probabilities = malloc(sizeof(float) * len);
    softmax(len, vector, 0);

    for (int i = 0; i < len - 1; i++)
    {
        softmax(len, NULL, vector[i]);
    }

    return probabilities;
}


float sigmoid(int x)
{
    return 1 / (1 + exp(-x));
}

float* sigmoid_vector(int len, const float* vector)
{
    float* result = malloc(sizeof(float) * len);

    for (int i = 0; i < len; i++)
    {
        result[i] = sigmoid(vector[i]);
    }

    return result;
}


float* multiply_vectors(int len, const float* v1, const float* v2)
{
    float* product_vector = malloc(sizeof(float) * len);

    for (int i = 0; i < len; i++)
    {
        product_vector[i] = v1[i] * v2[i];
    }

    return product_vector;
}


float* add_vectors(int len, const float* v1, const float* v2)
{
    float* addition_vector = malloc(sizeof(float) * len);

    for (int i = 0; i < len; i++)
    {
        addition_vector[i] = v1[i] + v2[i];
    }

    return addition_vector;
}

float sumof_vector(int len, const float* v1)
{
    float sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += v1[i];
    }

    return sum;
}