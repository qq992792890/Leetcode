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
        // string res = "";
        // int length = 0;
        // int strsize = s.length();
        // int start = 0, end = 0;
        // //when longer than length update res
        // if (strsize == 0)
        // {
        //     return "";
        // }
        
        // for (int i = 1; i < strsize; i++)
        // {
        //     end = i + 1;
        //     for (start = i-1; start >= 0; start--)
        //     {
        //         if (s[start] != s[end])
        //         {
        //             continue;
        //         }
                
        //         end ++;
        //     }
            
        // }




        //官方题解
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
        //官方题解
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        
         
    }
};

