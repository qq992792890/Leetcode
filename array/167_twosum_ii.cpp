#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;//vector is from the std namespace
using std::cin;
using std::cout;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if (numbers.size()<2)
        {
            return res;
        }
        int i,j;
        i=0;
        j=numbers.size()-1;
        while (i<j)
        {
            if (numbers[i]+numbers[j]>target)
            {
                --j;
            }else if (numbers[i]+numbers[j]<target)
            {
                ++i;
            }else {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
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
    // MySolution s;//check if my solution work
    res=s.twoSum(nums,target);
    cout<<"answer is:\n";
    for (int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<" ";
    }
    

    

    return 0;
}
//finish