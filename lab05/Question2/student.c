/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    int* h = (int*)malloc(k * sizeof(int));
    int s = 0;

    for (int i = 0; i < numsSize; i++) {
        if (s < k) {
            h[s] = nums[i];
            heapifyUp(h, s);
            s++;
        } else if (nums[i] > h[0]) {
            h[0] = nums[i];
            heapifyDown(h, k, 0);
        }
    }

    int ans = h[0];
    free(h);
    return ans;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) {
            break;
        }
        swap(&h[p], &h[i]);
        i = p;
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* h, int n, int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;

        if (l < n && h[l] < h[m]) {
            m = l;
        }
        if (r < n && h[r] < h[m]) {
            m = r;
        }
        if (m == i) {
            break;
        }

        swap(&h[i], &h[m]);
        i = m;
    }
}