#include <iostream>
#include <cassert>
#include "recursive_binary_search.h"

void test_basic_search() {
  int array[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
  int len = 10;
  
  // Test finding existing elements
  assert(rbs(array, 0, len, 3) == 0);   // First element
  assert(rbs(array, 0, len, 30) == 9);  // Last element
  assert(rbs(array, 0, len, 18) == 5);  // Middle element
  assert(rbs(array, 0, len, 15) == 4);  // Another element
  
  std::cout << "✓ Basic search tests passed\n";
}

void test_not_found() {
  int array[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
  int len = 10;
  
  // Test elements not in array
  assert(rbs(array, 0, len, 1) == -1);   // Less than minimum
  assert(rbs(array, 0, len, 35) == -1);  // Greater than maximum
  assert(rbs(array, 0, len, 10) == -1);  // Between existing elements
  assert(rbs(array, 0, len, 20) == -1);  // Between existing elements
  
  std::cout << "✓ Not found tests passed\n";
}

void test_single_element() {
  int array[] = {42};
  int len = 1;
  
  assert(rbs(array, 0, len, 42) == 0);   // Found
  assert(rbs(array, 0, len, 41) == -1);  // Not found (less)
  assert(rbs(array, 0, len, 43) == -1);  // Not found (greater)
  
  std::cout << "✓ Single element tests passed\n";
}

void test_two_elements() {
  int array[] = {10, 20};
  int len = 2;
  
  assert(rbs(array, 0, len, 10) == 0);   // First element
  assert(rbs(array, 0, len, 20) == 1);   // Second element
  assert(rbs(array, 0, len, 5) == -1);   // Not found (less)
  assert(rbs(array, 0, len, 15) == -1);  // Not found (between)
  assert(rbs(array, 0, len, 25) == -1);  // Not found (greater)
  
  std::cout << "✓ Two element tests passed\n";
}

void test_empty_array() {
  int* array = nullptr;
  int len = 0;
  
  assert(rbs(array, 0, len, 5) == -1);   // Search in empty array
  
  std::cout << "✓ Empty array tests passed\n";
}

void test_large_array() {
  int array[100];
  for (int i = 0; i < 100; i++) {
    array[i] = i * 2;  // Even numbers 0, 2, 4, ..., 198
  }
  int len = 100;
  
  assert(rbs(array, 0, len, 0) == 0);     // First element
  assert(rbs(array, 0, len, 198) == 99);  // Last element
  assert(rbs(array, 0, len, 100) == 50);  // Middle element
  assert(rbs(array, 0, len, 1) == -1);    // Odd number (not found)
  assert(rbs(array, 0, len, 199) == -1);  // Not found (greater)
  
  std::cout << "✓ Large array tests passed\n";
}

void test_duplicates() {
  int array[] = {1, 3, 3, 3, 5, 7, 9};
  int len = 7;
  
  // Should find one of the duplicate positions
  int result = rbs(array, 0, len, 3);
  assert(result >= 1 && result <= 3);  // Any of positions 1, 2, or 3
  assert(array[result] == 3);
  
  std::cout << "✓ Duplicates tests passed\n";
}

int main() {
  std::cout << "Running recursive binary search tests...\n\n";
  
  test_basic_search();
  test_not_found();
  test_single_element();
  test_two_elements();
  test_empty_array();
  test_large_array();
  test_duplicates();
  
  std::cout << "\n🎉 All tests passed!\n";
  return 0;
}
