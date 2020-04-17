/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //copy from comments with high likes
        int count = 1, size_s = nums.size();
		int maj = nums[0];
		for (int i = 1; i < size_s; i++) {
			if (maj == nums[i])
				count++;
			else {
				count--;
				if (count == 0) {//跳过当前数到后面去开始计算
					maj = nums[i + 1];
                    count = 1;
                    i += 1;
				}
			}
		}
		return maj;
    }
};

