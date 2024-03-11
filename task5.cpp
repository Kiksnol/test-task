#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void func(int *arr, int64_t size) {
    if (arr == nullptr) {
        return;
    }

    for (int64_t i = 0; i < size; ++i) {
        try {
            arr[i] *= 2;
        }
        catch (...) {
            std::cerr << "ERROR OCCURED\n";
            exit(EXIT_FAILURE);
        }
    }
}