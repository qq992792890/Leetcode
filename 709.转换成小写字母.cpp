/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
class Solution {
public:
    string toLowerCase(string str) {
        int size_str = str.size();
        for (int i = 0; i < size_str; i++)
        {
            if ('A' <= str[i] && str[i] <= 'Z')
            {
                str[i] = (str[i] + ('a' - 'A'));
            }
            
        }
        return str;
        
    }
};

