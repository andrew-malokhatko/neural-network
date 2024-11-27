#include "image.h"

int main()
{
    const char* train_file = "data/mnist_train.csv";
    const char* test_file = "data/mnist_test.csv";

    Image* images = images_from_csv(train_file, 10);

    print_image(images[0]);
}