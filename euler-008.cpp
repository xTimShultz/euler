// https://projecteuler.net/problem=8

// The four adjacent numbers in the 1000-digit number that have the
// greatest product are 9 × 9 × 8 × 9 = 5832.

// 73167176531330624919225119674426574742355349194934
// 96983520312774506326239578318016984801869478851843
// 85861560789112949495459501737958331952853208805511
// 12540698747158523863050715693290963295227443043557
// 66896648950445244523161731856403098711121722383113
// 62229893423380308135336276614282806444486645238749
// 30358907296290491560440772390713810515859307960866
// 70172427121883998797908792274921901699720888093776
// 65727333001053367881220235421809751254540594752243
// 52584907711670556013604839586446706324415722155397
// 53697817977846174064955149290862569321978468622482
// 83972241375657056057490261407972968652414535100474
// 82166370484403199890008895243450658541227588666881
// 16427171479924442928230863465674813919123162824586
// 17866458359124566529476545682848912883142607690042
// 24219022671055626321111109370544217506941658960408
// 07198403850962455444362981230987879927244284909188
// 84580156166097919133875499200524063689912560717606
// 05886116467109405077541002256983155200055935729725
// 71636269561882670428252483600823257530420752963450

// Find the thirteen adjacent numbers in the 1000-digit number that
// have the greatest product. What is the value of this product?
//
// Solution by Tim Shultz, Septembe 2021
//
// Use a simple loop "i" over the entire array of "numbers" with an
// inner loop "j" that calculates the product "new_product" of the
// next 13-digit sequence.

// The greatest product found so far is stored in "greatest_product".

// Note: Internally, numbers is represented as a string of characters, and
// converted to an int by subtracting 0x30 hex for ASCII conversion
// to a number.

#include <iostream>
#include <string>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using std::string;
using std::endl;
using std::cout;

string numbers =
    "73167176531330624919225119674426574742355349194934" 
    "96983520312774506326239578318016984801869478851843"
    "85861560789112949495459501737958331952853208805511"
    "12540698747158523863050715693290963295227443043557"
    "66896648950445244523161731856403098711121722383113"
    "62229893423380308135336276614282806444486645238749"
    "30358907296290491560440772390713810515859307960866"
    "70172427121883998797908792274921901699720888093776"
    "65727333001053367881220235421809751254540594752243"
    "52584907711670556013604839586446706324415722155397"
    "53697817977846174064955149290862569321978468622482"
    "83972241375657056057490261407972968652414535100474"
    "82166370484403199890008895243450658541227588666881"
    "16427171479924442928230863465674813919123162824586"
    "17866458359124566529476545682848912883142607690042"
    "24219022671055626321111109370544217506941658960408"
    "07198403850962455444362981230987879927244284909188"
    "84580156166097919133875499200524063689912560717606"
    "05886116467109405077541002256983155200055935729725"
    "71636269561882670428252483600823257530420752963450";

// Span size of digits for which to create a product
const int SPAN = 13;

int main()
{
    // Greatest product found so far
    unsigned long long greatest_product = 1;

    // True if a non-numeric value is found
    bool non_numeric = false;

    // For an input of sufficient size
    if (numbers.length() >= SPAN)
    {
        // Set origin for the next SPAN-size digit sequence
        for (int i  = 0; i < numbers.length() - SPAN; i++)
        {
            // Reset the product for this sequence to multiplicative identity
            unsigned long long new_product = 1;

            // Calculate the product for this sequence of digits
            for (int j = i; j < i + SPAN; j++)
            {
                // Convert number to int
                int num = numbers[j] - 0x30;

                // Only numeric digits are used
                if ((num >= 0) && (num <= 9))
                {
                    new_product = new_product * num;
                }
                else
                {
                    non_numeric = true;
                    break;
                }
            }
            // Save the greatest product calculated so far
            greatest_product = MAX(greatest_product, new_product);
        }
    }
    else
    {
        cout << "String too short" << endl;
    }
    if (non_numeric)
    {
        cout << "Non-numeric numbers" << endl;
    }    

    cout << greatest_product << endl;

    return 0;
}
