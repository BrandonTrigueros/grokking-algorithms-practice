// 4.3: Find the maximum number in a list

#include <iostream>

// APPROACH 1:
int* createSubArray(int* array, int size) {
    int* subArray = new int[size-1];
    for (int i = 1; i < size; i++) {
        subArray[i-1] = array[i];
    }
    return subArray;
}

int maximum1(int array[], int size) {
    // case base
    if (size == 1) return array[0];
    // recursive case
    int* subArray = createSubArray(array, size);
    int result = std::max(array[0], maximum1(subArray, size - 1));
    delete[] subArray;
    return result;
}

// APPROACH 2:
int maximum2(int array[], int size) {
    if (size == 1) return array[0];
    return std::max(array[0], maximum2(array + 1, size - 1));
}

int main() {
    int array[5] = {1, 2, 35, 4, 5};
    std::cout << maximum2(array, 5) << std::endl;
}