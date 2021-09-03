// https://projecteuler.net/problem=4
// A palindromic number reads the same both ways. The largest palindrome made from
// the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.
//
// Assume that the largest palindrome will be a 6-digit number.
// The largest 6-digit palindrome is 999999. The smallest is 100001
//
// So, we will start with forming palindromes by mirroring their
// 3-digit countersparts like 999 -> 999999, starting with the largest.
// This will give us a palindrome to solve for and a single factor.
// 
// We'll use another loop to find a second factor that produces the palindrome as
// a product. If we get a match, then we're done, since we start with the largest
// palindromes and work backwards to find their 3-digit factors.
//
// e.g. 999 (factor) 

#include <iostream>

using std::cout;
using std::endl;

unsigned int form_palindrome(unsigned int num)
{
    unsigned int ones = num % 10;
    unsigned int hundreds = num / 100;
    unsigned int tens = (num - ones - (hundreds * 100)) / 10;

    // Mirror and return result
    unsigned int result = (num * 1000) + (ones * 100) + (tens * 10) + hundreds;
    return result;
}

int main()
{
    for (unsigned int i = 999; i >= 100; i--)
    {
        unsigned int palindrome = form_palindrome(i);

        for (unsigned int factor1 = 100; factor1 * factor1 <= palindrome; factor1++)
        {
            // If factor1 is an evenly divisible factor, find factor2
            if (palindrome % factor1 == 0) 
            {
                unsigned int factor2 = palindrome / factor1;
                if ((palindrome % factor2 == 0) && (factor2 >= 100) && (factor2 <= 999))
                {
                    // Largest palindrome found
                    cout << palindrome << endl;
                    return 0;
                }
            }
        }
     }

     return 0;
}