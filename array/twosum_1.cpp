#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;//vector is from the std namespace
using std::cin;
using std::cout;

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

int main(int argc, char const *argv[])
{
    /* code */
    // Solution s;
    vector<int> nums={2,7,9,15};
    int target=9;
    // cout<<target<<"\n"<<nums[2]<<"\n";
    vector<int> res;
    Solution s;
    res=s.twoSum(nums,target);
    cout<<"answer is:\n";
    for (int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<" ";
    }
    

    

    return 0;
}
//finish