/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        //方法1 使用数组保存所有结果
        // vector<int> dp = vector<int>(size, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for (int i = 2; i < size; i++) {
        //     dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        // }
        // return dp[size - 1];
        //

        //方法2 仅仅保存需要的临时结果
         int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
        //


        


// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    }
};
// @lc code=end

