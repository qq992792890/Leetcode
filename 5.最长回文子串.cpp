/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
        //palindrome size can be odd or even
        //190819 unfinished waited to be done
        string res = "";
        int length = 0;
        int strsize = s.length();
        int start = 0, end = 0;
        //when longer than length update res
        if (strsize == 0)
        {
            return "";
        }
        
        for (int i = 1; i < strsize; i++)
        {
            end = i + 1;
            for (start = i-1; start >= 0; start--)
            {
                if (s[start] != s[end])
                {
                    continue;
                }
                
                end ++;
            }
            
        }
         
    }
};

