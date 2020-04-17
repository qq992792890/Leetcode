/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */
class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1,t2 = 1;
        int res = 0;
        if (n == 0)
        {
            return t0;
        }
        if (n == 1)
        {
            return t1;
        }
        if (n == 2)
        {
            return t2;
        }
        
        for (int i = 3; i <= n; i++)
        {
            res = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = res;

        }
        
        return res;
        
    }
};

