/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
class Solution {
public:
    string addBinary(string a, string b) {
        //加法器原理
        //1 转为二进制相加后用字符串表示
        //2 直接对二进制字符串进行运算，以较长的字符串作为循环体
        int size_a = a.size();
        int size_b = b.size();
        string res;
        char sum;
        int overflow;
        if (size_a > size_b)
        {
            b.insert(b.begin(), size_a - size_b, '0');
        }else if (size_a < size_b)
        {
            a.insert(a.begin(), size_b - size_a, '0');
        }
        
        size_a = a.size();
        overflow = 0;
        for (int i = size_a - 1; i >= 0; i--)
        {
            sum = char(a[i] - '0' + b[i] + overflow);
            if (sum > '1')
            {
                sum = char(sum - 2);
                overflow = 1;
                res.insert(res.begin(), sum);

            }else
            {
                overflow = 0;
                res.insert(res.begin(), sum);
            }
        }
        if (overflow == 1)
        {
            res.insert(res.begin(), '1');
        }
        return res;
        
        
    }
};

