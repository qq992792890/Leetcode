/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = 0;
        int body = 0;
        int len = word.length();
        if (('A' <= word[0]) && (word[0] <= 'Z'))
        {
            capital = 1;
        }else
        {
            capital = 0;
        }
        
        
        for (int i = 1; i < len; i++)
        {
            if (('A' <= word[i]) && (word[i] <= 'Z'))
            {
                body++;
            }
            
        }

        if ((capital + body == len) || (capital + body == 0))
        {
            return true;
        }else if (body != 0)
        {
            return false;
        }else
        {
            return true;
        }
        
        
        return false;
        
        
    }
};
// @lc code=end

