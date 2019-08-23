/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        //simple and clear solution
        //it is copied from the most voted one
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }
};

