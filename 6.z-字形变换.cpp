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

        //problems solved 190825, by the plan of myself 
        for (int j = 0; j < numRows; j++)
        {
            res.push_back(str0);
        }
        
        while (pos < size_s)
        {
            for (i = 0; i < numRows && pos < size_s; i++)
            {
                res[i].push_back(s[pos++]);
            }
            if (pos >= size_s) break; 
            
            
            //i = numRows - 1;

            
            for (i = numRows - 2; i > 0 && pos < size_s ; i--)
            {
                res[i].push_back(s[pos]);
                pos++;
            }
            if (pos >= size_s) break; 
            

        }
        
        string result;
        for (int k = 0; k < numRows; k++)
        {
            result += res[k];
        }
        return result;
        
    }
};

