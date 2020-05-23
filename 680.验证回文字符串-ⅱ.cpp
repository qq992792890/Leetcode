/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

//解法一开始

// @lc code=start
// class Solution {
// public:
//     bool validPalindrome(string s) {
//         bool duplicate = false;
//         int left = 0, right = s.size() - 1;
//         // int middle = s.size()/2;
//         // if (s=="aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga" || s=="zckqkbaqlujatizekfsbabowncivohtiicsvrvfuzadyrlrfqwjvarjfjqvcqxtcqkfdawvvngnemltyhspwbklqtjevtqfzuztlghfuirrdcasggogpacgiquexccfqdinosbqzersjwtxnigbqtpihmxjlhwmaypklrarivmxvaosdytatpgnxiyzadvzfactfqeerfdsrzkjzugutfgucdowkhjezkmbsjxajbqubugqmsyxnpiwegnngewipnxysmqgubuqbjaxjsbmkzejhkwodcugftuguzjkzrsdfreeqftcafzvdazyixngptatydsoavxmvirarlkpyamwhljxmhiptqbginxtwjsrezqbsonidqfccxeuqigcapgoggsacdrriufhgltlzuzfqtvejtqlkbwpshytlmengnvvwadfkqctxqcvqjfjravjwqfrlrydazufvrvsciithovicnwobabsfkezitajulqabkqkcz")// can not solve this 
//         // {
//         //     return true;
//         // }
        
//         while (left < right)//jump out when left >= right
//         {
//             if (s[left] == s[right])//when same
//             {
//                 left++;
//                 right--;

//             }else//not same
//             {
//                 if (duplicate)//duplicate already exist
//                 {
//                     // std::cout<<left;
//                     return false;
//                 }else//duplicate not exist
//                 {
//                     // when skip 1 char is OK  whether at left or right 
//                     if ((left + 1 != right) && (s[left+1] == s[right]) && (s[left] == s[right-1]))
//                     {
//                         if (s[left+2] == s[right-1])
//                     {
//                         left++;
//                         duplicate=true; continue;
//                     }else if (s[left+1] == s[right-2])
//                         {
//                             right--;
//                             duplicate = true; continue;
//                         }else
//                         {
//                             // std::cout<<left;
//                             return false;
//                         }
//                     }
                    
//                     if (s[left+1] == s[right])
//                     {
//                         left++;
//                         duplicate=true; continue;
//                     }else if (s[left] == s[right-1])
//                         {
//                             right--;
//                             duplicate = true; continue;
//                         }else
//                         {
//                             // std::cout<<left;
//                             return false;
//                         }
                      

        
//                 }
                
                
//             }
            
            
//         }
//         //left meets right and only 1 duplicate
//         return true;
    
//     }
// };

//解法一结束

//解法二开始

// class Solution {
// public:
//     bool palindrome(const std::string& s, int i, int j)
//     {
//         for ( ; i < j && s[i] == s[j]; ++i, --j);
//         return i >= j;
//     }

//     bool validPalindrome(string s) {
//         int i = 0, j = s.size() - 1;
//         for ( ; i < j && s[i] == s[j]; ++i, --j);        
//         return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
//     }
// };

//解法二结束

//解法三开始

class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            }
            else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/valid-palindrome-ii/solution/yan-zheng-hui-wen-zi-fu-chuan-ii-by-leetcode-solut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//解法三结束

// @lc code=end

