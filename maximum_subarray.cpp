/*
 * Wiki:
 * Kadane's algorithm: https://en.wikipedia.org/wiki/Maximum_subarray_problem
 *
 * LeetCode:
 * https://leetcode.com/problems/maximum-subarray/
**/

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currSum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (currSum < 0) {
            currSum = 0;
        }
        currSum = max(0, currSum) + nums[i];

        if (currSum > maxSum)
            maxSum = currSum;
    }
    return maxSum;
}

