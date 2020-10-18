/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //枚举法只能解决94/96个case
        //需要提交其他方法
        // int size = heights.size();
        // int ans = 0;
        // int min_height = INT_MAX;
        // for (int left = 0; left < size; left++)
        // {
        //     min_height = heights[left];
        //     for (int right = left; right < size; right++)
        //     {
        //         min_height = min(min_height, heights[right]);
        //         ans = max(ans, (right - left + 1) * min_height);
        //     }
            
        // }
        // return ans;
        //会超时的方法


        //一重枚举即可实现的方法及时这个方法还是超时，看来要用栈了
        // int n = heights.size();
        // int ans = 0;
        // for (int mid = 0; mid < n; ++mid) {
        //     // 枚举高
        //     int height = heights[mid];
        //     int left = mid, right = mid;
        //     // 确定左右边界
        //     while (left - 1 >= 0 && heights[left - 1] >= height) {
        //         --left;
        //     }
        //     while (right + 1 < n && heights[right + 1] >= height) {
        //         ++right;
        //     }
        //     // 计算面积
        //     ans = max(ans, (right - left + 1) * height);
        // }
        // return ans;
        //一重枚举即可实现的方法


        //第三种方法！
        //单调栈
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
        //单调栈


// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处.
        
    }
};
// @lc code=end

