#include <iostream>

template <typename T>
int binary_search(T list[], T item, int len) {
  int low = 0;
  int high = len - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (list[mid] == item) {
      return mid;
    }
    if (list[mid] < item) {
      low = mid + 1;
    }
    if (list[mid] > item) {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int intList[7] = {1, 2, 3, 4, 5, 8, 20};
  char* charArray = "abhyz";
  bool boolList[5] = {0, 0, 0, 0, 1};

  std::cout << binary_search(intList, 4, 7) << std::endl;
  std::cout << binary_search(intList, 6, 7) << std::endl;
  std::cout << binary_search(charArray, 'h', 5) << std::endl;
  std::cout << binary_search(boolList, true, 5) << std::endl;

  return 0;
}