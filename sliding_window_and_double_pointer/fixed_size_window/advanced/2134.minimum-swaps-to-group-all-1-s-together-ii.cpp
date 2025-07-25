/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 *
 * https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
 *
 * algorithms
 * Medium (65.54%)
 * Likes:    2043
 * Dislikes: 41
 * Total Accepted:    168.5K
 * Total Submissions: 257.1K
 * Testcase Example:  '[0,1,0,1,1,0,0]'
 *
 * A swap is defined as taking two distinct positions in an array and swapping
 * the values in them.
 * 
 * A circular array is defined as an array where we consider the first element
 * and the last element to be adjacent.
 * 
 * Given a binary circular array nums, return the minimum number of swaps
 * required to group all 1's present in the array together at any location.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1,0,1,1,0,0]
 * Output: 1
 * Explanation: Here are a few of the ways to group all the 1's together:
 * [0,0,1,1,1,0,0] using 1 swap.
 * [0,1,1,1,0,0,0] using 1 swap.
 * [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
 * There is no way to group all 1's together with 0 swaps.
 * Thus, the minimum number of swaps required is 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1,1,0,0,1,1,0]
 * Output: 2
 * Explanation: Here are a few of the ways to group all the 1's together:
 * [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the
 * array).
 * [1,1,1,1,1,0,0,0,0] using 2 swaps.
 * There is no way to group all 1's together with 0 or 1 swaps.
 * Thus, the minimum number of swaps required is 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,0,0,1]
 * Output: 0
 * Explanation: All the 1's are already grouped together due to the circular
 * property of the array.
 * Thus, the minimum number of swaps required is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    // The sum of array serves as the size of silding window.
    int minSwaps(vector<int>& nums) {
        int res_t = 0, sum = 0;
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);
        if (k == 0 || k == n) {
            return 0;
        }

        sum = accumulate(nums.begin(), nums.begin() + k, 0);
        res_t = sum;
        for (int i = 1; i < n; i++) {
            sum += nums[(i + k - 1) % n] - nums[(i - 1) % n];
            res_t = max(res_t, sum);
        }

        return k - res_t;
    }
};
// @lc code=end
