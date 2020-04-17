/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size_s = s.size();
        int tail = size_s - 1; //结尾处第一个字母
        int cnt = 0;
        while (tail > -1 && s[tail] == ' ')
        {
            tail --;
        }
        while (tail > -1 && s[tail] != ' ')
        {
            if (('a' <= s[tail] && s[tail] <= 'z') || ('A' <= s[tail] && s[tail] <= 'Z'))
            {

                tail--;
                cnt++;
            }
            else
            tail --;
            
        }
        return cnt;
    }
};

