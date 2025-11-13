#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include "searchUtils.h"

int main() {
    std::srand(std::time(nullptr)); // rastgele sayı üreticisini başlatır

    int n;
    std::cout << "Enter the size of the vector: ";
    std::cin >> n;

    auto arr = generateSortedVector(n);

    int linComp, binComp;
    int key;

    // WORST CASE (eleman yok)
    key = n + 1;  // dizide yok
    int linIndex = linearSearch(arr, key, linComp);
    int binIndex = binarySearch(arr, key, binComp);

    std::cout << "\n=== Worst case ===\n";
    std::cout << "Linear search: vector size = " << n << ", comparisons = " << linComp << "\n";
    std::cout << "Binary search: vector size = " << n << ", comparisons = " << binComp << "\n";

    // AVERAGE CASE (rastgele elemanlar)
    std::cout << "\n=== Average case (5 random keys) ===\n";
    int linSum = 0, binSum = 0;
    for (int i = 0; i < 5; ++i) {
        key = 1 + std::rand() % n;
        linearSearch(arr, key, linComp);
        binarySearch(arr, key, binComp);
        linSum += linComp;
        binSum += binComp;
        std::cout << "Test " << i + 1 << ": key=" << key
            << ", lin=" << linComp << ", bin=" << binComp << "\n";
    }
    std::cout << "Average linear = " << linSum / 5.0 << "\n";
    std::cout << "Average binary = " << binSum / 5.0 << "\n";

    return 0;
}
