/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        //使用堆栈实现，并维护一个最大堆栈长度大小
        //目前有问题卡在(()(((()这个例子
        //不能简单的用堆栈实现 未完成！！
        //碰到右括号且闭合时 size为奇数时继续想寻找 size偶数时尝试更新res
        //
        vector<char> cstack;
        vector<char> zero;
        int res = 0, size_s = s.size(), csize = 0;
        int cdepth = 0;
        int insidesize = 0;//嵌套括号的大小
        for (int i = 0; i < size_s; i++)
        {
            if (s[i] == ')')
            {
                if (!cstack.empty())
                {
                    if (cstack.back() == '(')
                    {
                        cstack.pop_back();
                        //括号深度未清零时左括号打断连续括号
                        if (cdepth == 1)
                        {
                            csize += 2;
                            if (insidesize != 0)
                            {
                                csize += insidesize;
                                insidesize = 0;
                            }
                            
                            insidesize = 0;
                            if (csize > res)
                            {
                                res = csize;
                            }
                            cdepth --;
                        }else//cdepth != 0
                        {
                            insidesize += 2;
                            if (insidesize > res)
                            {
                                res = insidesize;
                            }
                            cdepth--;
                            // if (cdepth == 1)
                            // {
                            //     csize+=insidesize;
                            // }
                            
                        }
                        
                        

                        // if (cstack.empty())
                        // {
                        //     csize = 0;
                        // }
                                        
                    }
                    //else if (cstack.back() == ')')
                    // {
                    //     cstack = zero;
                    // }
                    
                    
                }else {
                    csize = 0;//右括号打断连续括号
                    continue;
                }//i++
                
                
            }else if (s[i] == '(')
            {
                cstack.push_back('(');
                cdepth++;

            }

            
        }
        return res;
        
    }
};

