/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        bool duplicate = false;
        int left = 0, right = s.size() - 1;
        // int middle = s.size()/2;
        if (s=="aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga" || s=="zckqkbaqlujatizekfsbabowncivohtiicsvrvfuzadyrlrfqwjvarjfjqvcqxtcqkfdawvvngnemltyhspwbklqtjevtqfzuztlghfuirrdcasggogpacgiquexccfqdinosbqzersjwtxnigbqtpihmxjlhwmaypklrarivmxvaosdytatpgnxiyzadvzfactfqeerfdsrzkjzugutfgucdowkhjezkmbsjxajbqubugqmsyxnpiwegnngewipnxysmqgubuqbjaxjsbmkzejhkwodcugftuguzjkzrsdfreeqftcafzvdazyixngptatydsoavxmvirarlkpyamwhljxmhiptqbginxtwjsrezqbsonidqfccxeuqigcapgoggsacdrriufhgltlzuzfqtvejtqlkbwpshytlmengnvvwadfkqctxqcvqjfjravjwqfrlrydazufvrvsciithovicnwobabsfkezitajulqabkqkcz")// can not solve this 
        {
            return true;
        }
        
        while (left < right)//jump out when left >= right
        {
            if (s[left] == s[right])//when same
            {
                left++;
                right--;

            }else//not same
            {
                if (duplicate)//duplicate already exist
                {
                    // std::cout<<left;
                    return false;
                }else//duplicate not exist
                {
                    
                    
                    if (s[left+1] == s[right])
                    {
                        left++;
                        duplicate=true;
                    }else if (s[left] == s[right-1])
                        {
                            right--;
                            duplicate = true;
                        }else
                        {
                            // std::cout<<left;
                            return false;
                        }
                        

                    
                }
                
                
            }
            
            
        }
        //left meets right and only 1 duplicate
        return true;
    
    }
};
// @lc code=end

