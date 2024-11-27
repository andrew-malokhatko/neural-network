#pragma once

float softmax(int len, const float* vector, float item);
float* softmax_vector(int len, const float* vector);

// Mutates initial vector
float sigmoid(int x);
float* sigmoid_vector(int len, float* vector);

float* multiply_vectors(int len, const float* v1, const float* v2);
float* add_vectors(int len, const float* v1, const float* v2);
float sumof_vector(int lem, const float* v1);