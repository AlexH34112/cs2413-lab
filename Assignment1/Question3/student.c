#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.
                //  0 1 2 3          4            4
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int outSize = digitsSize;

    int *newray = (int*)malloc(sizeof(int) * (digitsSize + 1));
    if (newray == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < digitsSize; i++) {
        newray[i] = digits[i];
    }

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (newray[i] < 9) {
            newray[i] += 1;
            *returnSize = outSize;
            return newray;
        }
        newray[i] = 0;
    }

    newray[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        newray[i] = 0;
    }
    outSize = digitsSize + 1;
    *returnSize = outSize;
    return newray;
}