/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        //循环推演自底向上，因为只要知道了走3级和4级台阶的可能
        //就可轻松推演出5级台阶是3的加上4的
        //这好像就是裴波那契数列
        int res1 = 1, res2 = 2,res;
        if (n == 1) return 1;
        if (n == 2) return 2;

        for (int i = 3; i <= n; i++)
        {
            res = res1 + res2;
            res1 = res2;
            res2 = res;
        }
        return res;
    }
};

