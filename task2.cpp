#include <iostream>
#include <future>
#include <thread>

uint64_t result = 1;

uint64_t fact(uint32_t n) {
    return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
}

void factBetweenValues(uint32_t st, uint32_t end, uint32_t n) {
    if (end >= st) {
        result *= end;
        factBetweenValues(st, end - 1, n);
    }
}

std::future<uint64_t> calculateFactorialAsync(uint32_t n) {
    return std::async(std::launch::async, fact, n);
}

void calculateFactorialAsyncBetweenValues(uint32_t st, uint32_t end, uint32_t n) {
    std::async(std::launch::async, factBetweenValues, st, end, n);
}

int main() {
    int thread_num = 2;
    int n;

    std::cin >> n; // dlya factoriala

    std::vector<std::thread> threads;

    for (unsigned int i = 0; i < thread_num; ++i) {
        unsigned int start = i * (n / thread_num) + 1;
        unsigned int end = (i + 1) * (n / thread_num);

        if (i == thread_num - 1) {
            end = n;
        }

        threads.emplace_back(calculateFactorialAsyncBetweenValues, start, end, n);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "factorial: " << result;
}
