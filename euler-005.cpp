// https://projecteuler.net/problem=5
// 2520 is the smallest number that can be divided by each of the
// numbers from 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible
// by all of the numbers from 1 to 20?
//
// Solution by Tim Shultz, September 2021
//
// Given the problem statement, we will start our search at 2520 and increase.
// We will increase by 20, since a candidate number must be divisible by
// 20 anyway, and this will optimize the search somewhat.
// 
// Since all numbers are divisible by 1, we will skip that as well.
// Knowing that the search starts at 2520 and increments by 20,
// we will also skip 2 for testing even divisors. We can also skip the test
// for 20, since our increment of candidate numbers only chooses numbers
// divisible by 20.
//
// Algorith will iterative test 2520 + n*20 against {3..19}.
// Naive implementation would be to just start counting up by 1 and
// testing 2521, 2522, ... against a loop checking 
//
// Note that additional optimizations are possible, since for example,
// numbers divisible 3 don't need to be tested if they are also divisible by 6.
// However, the solution below proves sufficiently fast for now.
//
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    unsigned int smallest = 2520;

    bool found = false;

    // Try candidate numbers from 2520, 2540, ... until evenly divisible number found
    while (!found)
    {
        bool divisible = true;

        // Chosen starting point 2520 and increment +20 guarantees 1, 2, 20 not needed
        // Must be divisible by all other numbers in loop or divisible set false.
        for (int i = 3; i <= 19; i++)
            if (smallest % i != 0)  
            {
                divisible = false; 
                break;
            }

        if (divisible)
            found = true; // Terminate, with result in smallest
        else
            smallest += 20; // Continue searching
    }

    cout << smallest << endl;

    return 0;
}