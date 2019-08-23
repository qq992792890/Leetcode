/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n1 = 0,n2 = 0,n3 = 0;
        int temp = 0, numsmax = nums.size();
        vector<vector<int>> res ;
        vector<int> part;
        bool skip = false;
        std::sort(nums.begin(),nums.end());

        
        for (int i = 0; i < numsmax -2; i++)
        {
            n1 = nums[i];
            if (n1 > 0)
            {//if first digit > 0 there is no more answer after that
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {//skip same digits
                continue;
            }
            //then it becomes two sum problems
            int j = i + 1,k = numsmax - 1;
            while (j < k)
            {
                temp = nums[i] + nums[j] + nums[k];
                if (temp < 0)
                {
                    j += 1;
                    while (nums[j] == nums[j - 1] && j < k)
                    {
                        j += 1;
                    }
                    
                }else
                {
                    if (temp > 0)
                    {
                        k -= 1;
                        while (nums[k] == nums[k + 1] && j < k)
                        {
                            k -= 1;
                        }
                        
                    }else
                    {
                        //temp = 0
                        part.push_back(nums[i]);
                        part.push_back(nums[j]);
                        part.push_back(nums[k]);
                        res.push_back(part);
                        part.clear();

                        j += 1;
                        while (nums[j] == nums[j - 1] && j < k)
                        {
                            j += 1;
                        }
                        k -= 1;
                        while (nums[k] == nums[k + 1] && j < k)
                        {
                            k -= 1;
                        }
                    }
                    
                    
                }
                
                
            }

        }

        return res;
        
    }
};

