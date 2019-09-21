/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        //使用堆栈实现，并维护一个最大堆栈长度大小
        //目前有问题卡在()(())这个例子
        //不能简单的用堆栈实现 未完成！！
        vector<char> cstack;
        vector<char> zero;
        int res = 0, size_s = s.size();
        for (int i = 0; i < size_s; i++)
        {
            if (s[i] == ')')
            {
                if (cstack.size() != 0)
                {
                    if (cstack.back() == '(')
                    {
                        cstack.push_back(s[i]);
                        if (cstack.size() > res)
                        {
                            res = cstack.size();
                        }
                    }else if (cstack.back() == ')')
                    {
                        cstack = zero;
                    }
                    
                    
                }else continue;
                
                
            }else if (s[i] == '(')
            {
                if (cstack.empty() || cstack.back() == ')')
                {
                    cstack.push_back(s[i]);
                }else if (cstack.back() == '(')
                {
                    cstack = zero;
                    cstack.push_back('(');
                }
                
                
                
            }

            
        }
        return res;
        
    }
};

