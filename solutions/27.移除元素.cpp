/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        int i = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                continue;
            }else
            {
                nums[index] = nums[i];
                index ++;
            }
            
            
        }
        return index;
    }
};

