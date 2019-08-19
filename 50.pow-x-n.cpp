/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        //learn from official answer suggest
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i != 0; i /= 2)
        {
            //see N as binary
            //like 1101101010
            //from right to left 
            //when we meet 1 ans = ans * currentproduct
            //this can turn power to times
            if ((i % 2) == 1)
            {
                ans = ans * current_product;
            }
            current_product *=current_product;
            //current_product = x^(2^i);
        }
        return ans;
        
        
    }
};

