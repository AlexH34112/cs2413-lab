#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
    int b = numsSize / 2;

    int mj1[2] = {nums[0], 1};
    int mj2[2] = {nums[0], 1};
    int spot = 0;

    for (int a = 0; a < numsSize; a++) {
        mj2[0] = nums[spot];
        mj2[1] = 0;

        for (int c = 0; c < numsSize; c++) {
            if (mj2[0] == nums[c]) {
                mj2[1]++;
            }
        }

        if (mj2[1] > mj1[1]) {
            mj1[0] = mj2[0];
            mj1[1] = mj2[1];
        }

        if (mj1[1] > b) {
            return mj1[0];
        }

        spot++;
    }

    return mj1[0];
}
