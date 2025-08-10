#include "recursive_binary_search.h"

int rbs(int array[], int index, int len, int item) {
  if (index >= len) return -1;
  if (array[index] == item) return index;
  int mid = index + ((len - index) / 2);
  if (mid == index) return -1;
  return array[mid] <= item ? rbs(array, mid, len, item) : rbs(array, index, mid, item);
}
