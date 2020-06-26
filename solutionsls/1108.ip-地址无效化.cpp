/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */
class Solution {
public:
    string defangIPaddr(string address) {
        
        //解法一
        int size_s = address.size();
        for (int i = 0; i < size_s; i++)
        {
            if (address[i] == '.')
            {
                address.replace(i,1,"[.]");
                size_s += 2;
                i += 2;
            }
            
        }
        return address;
        //解法一
        

        //解法二 //未完成
        // string res = "";
        // for (char i = 0; i < count; i++)
        // {
        //     /* code */
        // }
        
        //解法二
    }
};

