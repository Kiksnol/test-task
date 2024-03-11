#include <iostream>

#define THRESHOLD 0.001

float function( float x, float y ) {
    return x * x - 4 + y * y + 6 * x * y;    
}

float df_dx(float x, float y) {
    return 2 * x + 6 * y;
}

float df_dy(float x, float y) {
    return 2 * y + 6 * x;
}

void grad(float &x, float &y, float learning_rate, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        float gradient_x = df_dx(x, y);
        float gradient_y = df_dy(x, y);

        x = x - learning_rate * gradient_x;
        y = y - learning_rate * gradient_y;
    }
}

int main() {
    float x = 10 - THRESHOLD, y = 10 - THRESHOLD;
    int it = 10000;

    grad(x, y, THRESHOLD, it);

    std::cout << "min val: " << f(x, y) << std::endl;

    return 0;
}