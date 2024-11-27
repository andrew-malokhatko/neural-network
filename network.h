#pragma once

#include "image.h"

typedef struct Network
{
    Image* train_data; 
    Image* test_data;

    float** w1;
    float** w2;
    float* b1;
    float* b2;
    
    float* input_layer;
    float* hidden_layer;
    float* output_layer;
} Network;

const output_size;
const hiddent_size;
const input_size;

Network create_network(Image* train_data, Image* test_data);
float* generate_weights(int from, int to);
float* generate_biases(int n);
void train_network(Network network, int count);