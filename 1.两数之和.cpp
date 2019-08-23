/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() < 2) return res;

        vector<int> pos(nums);
        sort(pos.begin(), pos.end());

        int i = 0;
        int j = pos.size() - 1;
        while (i < j) {
            if (pos[i] + pos[j] < target)
                ++ i;
            else if (pos[i] + pos[j] > target)
                -- j;
            else
                break;
        }

        for (int k=0; k<nums.size(); ++k) {
            if (nums[k] == pos[i]) {
                res.push_back(k);
                continue;
            }
            if (nums[k] == pos[j]) {
                res.push_back(k);
                continue;
            }
        }
        return res;
    }
};

