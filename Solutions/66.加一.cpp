/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //加法器原理，最后一位加一，如果溢出当位为零，
        //前一位+1 前一位溢出，在前一位加一，如果溢出，
        //当左边没有数了，则在左侧插入1
        vector<int> res = digits;
        int current = res.size()-1;
        while (current >= 0)
        {
            if(res[current] == 9){//溢出
                res[current] = 0;//赋值不小心写成了判等，好久也没看出来
                if (current == 0)
                {
                    res.insert(res.begin(), 1);
                }
                
                current --;//if current = 0 will break else will
                continue;

            }else
            {
                res[current] += 1;//不溢出
                break;
            }
            
        }
        
        
        return res;
        
        
    }
};

