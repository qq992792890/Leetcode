/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if ((x < 0)||(x != 0 && x % 10 ==0))return false;

        int tail = 0; //reverse of tail dec
        //if x = 12321 you get tail = 123
        //if x = 1221 you get tail = 12
        while(x>tail)
        {
            // tail *= 10;
            tail = tail*10 + x % 10;
            x /= 10;
        }

        return (tail==x)||(x==tail/10);
    
    }
};

