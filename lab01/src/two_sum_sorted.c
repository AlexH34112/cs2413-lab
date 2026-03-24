#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    int a = 0;
    int b = n - 1;
    while (a < b) 
    {
        if ((nums[a] + nums[b]) == target) 
        {
            *out_i = a;
            *out_j = b;
            return 1;
        } 
        else if((nums[a] + nums[b]) < target) {
            a++;
        } else {
            b--;
        }
    }
    return 0;
}
// think about the time complexity and space complexity of your solution

