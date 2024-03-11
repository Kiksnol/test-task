#include <iostream>
#include <future>

uint64_t fact(uint32_t n) {
    return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
}

std::future<uint64_t> calculateFactorialAsync( uint32_t n ) {
    return std::async(std::launch::async, fact, n);
}
