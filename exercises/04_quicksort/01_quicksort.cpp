#include <iostream>

int choosePivot(int* array, int begin, int end) {
    srand(time(0));
    return begin + rand() % (end - begin + 1);
}

int partition(int* array, int begin, int end) {
    int pivotPos = choosePivot(array, begin, end);
    int pivotValue = array[pivotPos];
    std::swap(array[pivotPos], array[begin]);

    int i = begin;
    int j = end;
    while (i < j) {
        while (i <= end && array[i] <= pivotValue) {
            ++i;
        }
        while (j >= begin && array[j] > pivotValue) {
            --j;
        }
        if (i < j) std::swap(array[i], array[j]);
    }
    std::swap(array[begin], array[j]);
    return j;
}

void quicksort (int* array, int begin, int end) {
    if (begin < end) {
        int pivotPos = partition(array, begin, end);
        quicksort(array, begin, pivotPos - 1);
        quicksort(array, pivotPos + 1, end);
    }
}

void printArray(int* array, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
} 

int main () {
    int array[5] = {4, 5, 1, 19, 3};
    quicksort(array, 0, 4);
    printArray(array, 5);
    return 0;
}