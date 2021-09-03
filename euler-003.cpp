// https://projecteuler.net/problem=3

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?
//
// Solution by Tim Shultz, September 2021
//
// Similar to a sieve, this will test factors counting up from 2, not exceeding sqrt(n).
// However, this is not an actual sieve, due to memory requirements.
//
// If we find an evenly divisible number, we will factor it out
// from our test number: "reduce" until our largest prime is in "reduce"
// 
// Note that this will also test non-primes, but since we're counting up,
// we will already have factored out the smaller prime factors composing it
// from the result.
//
#include <iostream>

using std::cout;
using std::endl;

int main ()
{
   unsigned long long reduce = 100; //600851475143;

   // factor * factor <= reduce is equivalent to not exceeding sqrt(n)
   for (unsigned long long factor = 2; factor * factor <= reduce; factor++ )
   {
      cout << factor << endl;

      // If it's evenly divisible (a factor) and not our largest prime,
      // continue reducing to the largest prime.
      while ( reduce % factor == 0 && reduce != factor)
      {
         cout << "Reducing " << reduce << " by " << factor << " = " << reduce / factor << endl;
         reduce /= factor;
      }
   }

   cout << reduce << endl;
   return 0;
}