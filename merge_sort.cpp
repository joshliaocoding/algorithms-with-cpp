#include <iostream>
#include <vector>

// Merge two sorted subarrays arr[left..mid] and arr[mid+1..right]
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < static_cast<int>(leftArr.size()) && j < static_cast<int>(rightArr.size())) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < static_cast<int>(leftArr.size())) {
        arr[k++] = leftArr[i++];
    }

    while (j < static_cast<int>(rightArr.size())) {
        arr[k++] = rightArr[j++];
    }
}

// Recursive merge sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Original array: ";
    for (int v : arr) std::cout << v << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    std::cout << "Sorted array: ";
    for (int v : arr) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
