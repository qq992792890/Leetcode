/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size_s = nums.size();
        int i = 0, place = 0;
        //可以使用二分查找法
        
        if (nums[0] > target)
        {
            return 0;
        }
        if (nums[size_s-1] < target)
        {
            return size_s;
        }
        for (i = 0; i < size_s; i++)
        {
            if (target == nums[i])
            {
                return i;
            }
        }

        for ( i = 1; i < size_s; i++)
        {
            if (nums[i-1] < target && target < nums[i])
            {
                return i;
            }
            
        }
        return 0;
        
        
    }
};

