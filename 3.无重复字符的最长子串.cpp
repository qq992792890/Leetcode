/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start =0;//, end = 0;
        int res = 0;//end - start
        int strsize = s.length();
        if (strsize == 0)
        {
            return 0;
        }
        
        for (int i = 1; i < strsize; i++)
        {
            for (int  j = start; j <= i-1; j++)
            {
                if (s[i] == s[j])
                {
                    start = j + 1;//skip the duplicate to get the substring
                    break;
                } 
            }
            res = res > (i - start) ? res : i - start;
        }

        return res + 1;
        //abcabcba
        //01234567
        //when start = 0, i = 2, 
        //res = i - start + 1 = 3 
        //substr = abc
        
    }
};

