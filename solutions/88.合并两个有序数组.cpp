/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (j >= 0)
        {
            nums1[tail--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        }
        
        
    }
};

