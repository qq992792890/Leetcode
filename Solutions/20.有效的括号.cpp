/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)
        {
            return true;
        }
        if (s.size() == 1)
        {
            return false;
        }

        string stack;
        //string stack = "" + s[0];
        //string stack("" + s[0]);
        //above are all wrong
        stack.push_back(s[0]);
        int i = 0;
        for (i = 1; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                stack.push_back('(');
                break;
            case ')':
                if (stack.back() == '(')
                {
                    stack.pop_back();
                }else
                {
                    //stack.push_back(')');
                    return false;
                }
                

                break;
            case '[':
                stack.push_back('[');
                break;
            case ']':
                if (stack.back() == '[')
                {
                    stack.pop_back();
                }
                else
                {
                    //stack.push_back('[');
                    return false;
                }
                break;
            case '{':
                stack.push_back('{');
                break;
            case '}':
                if (stack.back() == '{')
                {
                    stack.pop_back();
                }
                else
                {
                    //stack.push_back('{');
                    return false;
                }
                break;
            default:
                break;
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};

