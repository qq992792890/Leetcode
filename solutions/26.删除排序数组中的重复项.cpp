/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int index = 0;
        for ( i = 0; i < nums.size(); i++)
        {
            if (index == 0 || nums[i] > nums[i-1])
            {
                nums[index] = nums[i];
                index++;
            }
            
        }
        return index;
        

    }
};

