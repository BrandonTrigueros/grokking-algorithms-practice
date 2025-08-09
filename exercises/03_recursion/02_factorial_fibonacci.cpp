#include <iostream>

// Factorial function using recursion
int factorial(int i) {
    if (i <= 1) return 1;  // <- Base case: 0! = 1 and 1! = 1
    int fact = i * factorial(i - 1);  // <- Recursive case: n! = n * (n-1)!
    return fact;
}

// Fibonacci function using recursion
int fibonacci(int i) {
    if (i <= 1) return i;  // <- Base cases: fib(0) = 0, fib(1) = 1
    int fibo = fibonacci(i - 1) + fibonacci(i - 2);  // <- Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fibo;
}

int main () {
    std::cout << factorial(4) << '\n';
    std::cout << fibonacci(3) << '\n';
    return 0;
}

/* Manual execution trace for factorial(4):
    0 -------------------------------
    calls factorial with 4

    1 -------------------------------
    4 > 1, so we calculate 4 * factorial(3)
    calls factorial with 3

    2 -------------------------------
    3 > 1, so we calculate 3 * factorial(2)
    calls factorial with 2

    3 -------------------------------
    2 > 1, so we calculate 2 * factorial(1)
    calls factorial with 1

    4 -------------------------------
    1 <= 1, returns 1 to 3

    3 -------------------------------
    returns 2 * 1 = 2 to 2

    2 -------------------------------
    returns 3 * 2 = 6 to 1

    1 -------------------------------
    returns 4 * 6 = 24 to 0

    0 -------------------------------
    factorial(4) = 24
*/

/* Manual execution trace for fibonacci(3):
    0 -------------------------------
    calls fibonacci with 3

    1 -------------------------------
    3 > 1, so we calculate fibonacci(2) + fibonacci(1)
    calls fibonacci with 2

    2 -------------------------------
    2 > 1, so we calculate fibonacci(1) + fibonacci(0)
    calls fibonacci with 1

    3 -------------------------------
    1 <= 1, returns 1 to 2
    now calls fibonacci with 0

    4 -------------------------------
    0 <= 1, returns 0 to 2

    2 -------------------------------
    returns 1 + 0 = 1 to 1
    now calls fibonacci with 1

    5 -------------------------------
    1 <= 1, returns 1 to 1

    1 -------------------------------
    returns 1 + 1 = 2 to 0

    0 -------------------------------
    fibonacci(3) = 2
*/