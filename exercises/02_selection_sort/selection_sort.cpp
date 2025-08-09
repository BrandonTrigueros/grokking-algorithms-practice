// TODO: implement ADT List and its algorithms
// both as Array and as Linked List

#include <iostream>

template <typename T>
void printArray(T array[], int len) {
  for (int i = 0; i < len; ++i)
  {
    std::cout << array[i] << " ";
  }
}

template <typename T>
int findLower(T array[], int len, int index) {
  T lower = array[index];
  int lowerIndex = index;
  for (int j = index; j < len; j++)
  {
    if (array[j] < lower) {
      lower = array[j];
      lowerIndex = j;
    }
  }
  return lowerIndex;
}

// TODO: Make it recieve a ADT List
template <typename T>
void selectionSort(T array[], int len) {
  for (int i = 0; i < len; ++i) {
    int lower = findLower(array, len, i);
    std::swap(array[i], array[lower]);
  }
}

int main() {
  int array[14] = {1, 2, 8, 4, 6, 2, 5, 23, 6, 34, 64, 23, 45, 55};
  selectionSort(array, 14);
  printArray(array, 14);
  return 0;
}