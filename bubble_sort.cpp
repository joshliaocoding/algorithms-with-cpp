#include <iostream>
#include <vector>

// BubbleSort function
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Track whether any swaps occurred in this pass
        bool swapped = false;
        
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
