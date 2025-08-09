// 4.1: You’re given an array of numbers. 
// You have to add up all the numbers and return the total recursively.

#include <iostream>


int addArray(int* array, int size) {
    // case base
    if (size == 0) return 0;
    // recursive case
    return array[0] + addArray(array + 1, size - 1);                           
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    std::cout << addArray(array, 5) << std::endl;
}