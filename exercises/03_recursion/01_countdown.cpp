#include <iostream>

// Wrong approach to demonstrate infinite loop
void badCountdown(int i) {
    std::cout << i << std::endl;
    badCountdown(i-1);  // <- No base case, this will run out of memory!!
}

// Correct approach to recursion
void niceCountdown(int i) {
    std::cout << i << std::endl;
    if (i == 0) return; // <- Base cases are necessary in recursion
    niceCountdown(i-1); // <- Recursive case is the other important element
}

int main () {
    //badCountdown(5);
    niceCountdown(5);
    return 0;
}

/* Manual execution trace for i = 3:
    0 -------------------------------
    calls countdown with 3

    1 -------------------------------
    prints 3
    3 != 0
    calls countdown with 3 - 1 = 2

    2 -------------------------------
    prints 2
    2 != 0
    calls countdown with 2 - 1 = 1

    3 -------------------------------
    prints 1
    1 != 0
    calls countdown with 1 - 1 = 0

    4 -------------------------------
    prints 0
    0 = 0
    returns to 3

    3 -------------------------------
    3 has no more instructions
    Returns to 2

    2 -------------------------------
    2 has no more instructions
    Returns to 1

    1 -------------------------------
    1 has no more instructions
    Returns to 0

    0 -------------------------------
    0 has no more instructions
    Exits the program

*/