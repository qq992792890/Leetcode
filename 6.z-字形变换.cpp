/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int size_s = s.size(), pos = 0, i = 0;
        vector<string> res;
        string str0;
        int end = 0;

        //problems unsolved now ,waiting to be done 
        for (int j = 0; j < numRows; j++)
        {
            res.push_back(str0);
        }
        
        while (pos < size_s)
        {
            if (pos + numRows > size_s)
            {
                end = size_s - pos;
            }else
            {
                end = numRows;
            }
            
            
            for (i = 0; i < end; i++)
            {
                res[i].push_back(s[pos]);
                pos++;
            }
            //i = numRows - 1;

            if (pos + numRows - 2 > size_s)
            {
                end = size_s - pos;
            }
            else
            {
                end = numRows;
            }
            for (i = numRows - 2; i > numRows - 2 - end; i--)
            {
                res[i].push_back(s[pos]);
                pos++;
            }

        }
        
        string result;
        for (int k = 0; k < numRows; k++)
        {
            result += res[k];
        }
        return result;
        
    }
};

