/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 *
 * https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
 *
 * algorithms
 * Medium (42.64%)
 * Likes:    2108
 * Dislikes: 46
 * Total Accepted:    215.6K
 * Total Submissions: 505.7K
 * Testcase Example:  '[1,5,4,2,9,9,9]\n3'
 *
 * You are given an integer array nums and an integer k. Find the maximum
 * subarray sum of all the subarrays of nums that meet the following
 * conditions:
 * 
 * 
 * The length of the subarray is k, and
 * All the elements of the subarray are distinct.
 * 
 * 
 * Return the maximum subarray sum of all the subarrays that meet the
 * conditions. If no subarray meets the conditions, return 0.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,4,2,9,9,9], k = 3
 * Output: 15
 * Explanation: The subarrays of nums with length 3 are:
 * - [1,5,4] which meets the requirements and has a sum of 10.
 * - [5,4,2] which meets the requirements and has a sum of 11.
 * - [4,2,9] which meets the requirements and has a sum of 15.
 * - [2,9,9] which does not meet the requirements because the element 9 is
 * repeated.
 * - [9,9,9] which does not meet the requirements because the element 9 is
 * repeated.
 * We return 15 because it is the maximum subarray sum of all the subarrays
 * that meet the conditions
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,4,4], k = 3
 * Output: 0
 * Explanation: The subarrays of nums with length 3 are:
 * - [4,4,4] which does not meet the requirements because the element 4 is
 * repeated.
 * We return 0 because no subarrays meet the conditions.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */
 #include <vector>
 #include <unordered_map>
 #include <iostream>
 using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> freq;
        freq.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ++freq[nums[i]];

            if (i < k - 1) {
                continue;
            }

            if (freq.size() == k) {
                res = max(res, sum);
            }

            sum -= nums[i - k + 1];
            if (--freq[nums[i - k + 1]] == 0) {
                freq.erase(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

