#pragma once
#include <vector>

// --- Linear search ---
int linearSearch(std::vector<int>& arr, int key, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < arr.size(); ++i) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// --- Iterative binary search ---
int binarySearch(const std::vector<int>& arr, int key, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// --- Generate sorted vector ---
std::vector<int> generateSortedVector(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;
    return arr;
}
#pragma once
