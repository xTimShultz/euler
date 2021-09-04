// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
// we can see that the 6th prime is 13.
//
// What is the 10,001st prime number?

// Solution by Tim Shultz, September 2021
//
// Prime numbers are divisible only by themselves and 1.
// The first few prime numbers are 2, 3, 5, 7, 11, 13, 17, 19, 23, ...
// 
// To solve this, we'll store an array prime[] of all preceding prime numbers 
// Any candidate prime numbers we test, should not be divisible
// by a number in that list of primes.
//
// As prime numbers are found, they are added to the array prime[] and
// the size primes_size is incremented.
//
// Initially, start with first prime of 2, then look for candidate primes starting at 3.
// The candidate-prime increments by 2, since even numbers other than 2
// are not prime numbers.

#include <iostream>

using std::cout;
using std::endl;

const int LIMIT = 10001;

// Store 10001 Primes
int primes[10001] = {2}; // First element of prime number initialized to 2
int primes_size = 1; // size of the primes_array

int main()
{
    // Look for candidate prime numbers 3, 5, 7, 9, ...
    for (int candidate_prime = 3; primes_size < LIMIT; candidate_prime += 2)
    {
        // If the candidate number is divisible by any previously stored
        // prime number, it is not a prime number.
        bool is_prime = true;
        for (int i = 0; i < primes_size; i++)
            if (candidate_prime % primes[i] == 0)
            {
                is_prime = false;
                break;
            }
        // Candidate was not divisible, so store it as a new prime
        if (is_prime)
        {
            primes[primes_size] = candidate_prime;
            primes_size++;
        }
     }
    cout << primes[LIMIT - 1] << endl;

    return 0;
}