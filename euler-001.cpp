// https://projecteuler.net/problem=2
// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.
//
// Solution by Tim Shultz, September 2021
//
// Iterates through numbers 1..n, and sums the numbers evenly divisible by 3 or 5.
//
// Evenly divisible numbers have no remainder when divided by 3 or 5, and are
// identified with (i % 3 == 0) || (i % 5 == 0)
// This algorithm is O(n)

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    unsigned sum = 0;

    // Note: zero is not a natural number
    // A more optimal solution could use two counters incremented by 3 & 5 respectively
    // An even more optimal solution would use the observation that sum = (n/2)(n+1)
    
    for (unsigned i = 1; i < 1000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0)) 
        {
            sum += i;
        }
    }

     cout << "Sum is " << sum << endl;
}