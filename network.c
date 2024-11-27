#include "network.h"
#include "utils.h"
#include <stdlib.h>
#include <time.h>

const input_size = 784;         // FIX CONSTANT
const hiddent_size = 20;
const output_size = 10;

Network create_network(Image* train_data, Image* test_data)
{
    srand(time(NULL));

    Network network = {
        .train_data = train_data,
        .test_data = test_data,
        .w1 = generate_weights(hiddent_size, input_size),
        .w2 = generate_weights(output_size, hiddent_size),
        .b1 = generate_biases(hiddent_size),
        .b2 = generate_biases(output_size),
        .input_layer = malloc(sizeof(float) * input_size),
        .hidden_layer = malloc(sizeof(float) * hiddent_size),
        .output_layer = malloc(sizeof(float) * output_size),
    };

    return network;
}

float* generate_weights(int from, int to)
{
    float** all_weights = malloc(sizeof(float*) * to);

    for (int i = 0; i < to; i++)
    {
        float* node_weights = malloc(sizeof(float) * from);

        for (int k = 0; k < from; k++)
        {
            node_weights[i] = (float)rand() / (float)RAND_MAX;
        }
        all_weights[i] = node_weights;
    }

    return all_weights;
}

float* generate_biases(int n)
{
    float* biases = malloc(sizeof(float) * n);

    for (int i = 0; i < n; i++)
    {
        biases[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f;
    }
    
    return biases;
}

void predict_image(Network network, Image image)
{

    // Networks first layer is all the pixels from the 28x28 (784) image. 
    network.input_layer = image.pixels;
    
    // Calculate hidden layer. Weight all connections and find their sum
    float** hidden_weighted_connections = malloc(sizeof(float*) * hiddent_size);

    for (int i = 0; i < hiddent_size; i++)
    {
        hidden_weighted_connections[i] = multiply_vectors(input_size, network.input_layer, network.w1[i]);
        network.hidden_layer[i] = sumof_vector(input_size, hidden_weighted_connections[i]);
    }

    // Add biases to nodes in hidden layer and apply sigmoid function.
    network.hidden_layer = add_vectors(hiddent_size, network.hidden_layer, network.b1);
    network.hidden_layer = sigmoid_vector(hiddent_size, network.hidden_layer);

    // Repeat for output layer and apply softmax to get probabilities.
    float** output_weighted_connections = malloc(sizeof(float) * output_size);

    for (int i = 0; i < output_size; i++)
    {
        output_weighted_connections[i] = multiply_vectors(hiddent_size, network.hidden_layer, network.w2[i]);
        network.output_layer[i] = sumof_vector(hiddent_size, output_weighted_connections[i]);
    }

    // Add biases and apply softmax function to final output layer.
    float* output_connections = add_vectors(size * size, output_weighted_connections, network.b1);
    network.output_layer = softmax_vector(output_size, network.output_layer);
}