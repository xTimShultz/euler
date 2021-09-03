// The sum of the squares of the first ten natural numbers is,
//     1^2 + 2^2 +...+10^2 = 385

// The square of the sum of the first ten natural numbers is,
//     (1 + 2 + ... + 10)^2 = 55^2 = 3025

// Hence the difference between the sum of the squares of the first ten
// natural numbers and the square of the sum is 3025 - 385 = 2640.

// Find the difference between the sum of the squares of the first 
// one hundred natural numbers and the square of the sum.
//
// Solution by Tim Shultz, September 2021
//
// Uses a single loop from 1 to 100 with two acculators.
// 1) sum_squares = sum of the squares
// 2) square_sum = square of the sum
//
// note that squaring of the sum happens after the loop.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    unsigned long long sum_squares = 0;
    unsigned long long square_sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        sum_squares += i*i;
        square_sum += i;
    }

    square_sum *= square_sum; // Square the sum
    
    cout << square_sum - sum_squares << endl;
    return 0;
}